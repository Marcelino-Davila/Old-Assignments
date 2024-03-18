import pygame.locals as keys

class PlayerState:
    """
    Base class for the player's state machine.
    """
    def __init__(self, parent, anim=None, flip=False):
        """
        Initialize parent (the player), an animation
        to switch to on entry for the state, and
        the horizontal orientation.
        @parent : Reference to the player object.
        @anim : Name of the animation to play on
        entry, if any.
        @flip : Horizontal flip for the animation
        as a boolean.
        """
        self.parent = parent
        self.flip = flip
        if anim:
            self.parent.anim.change(anim)
        self.parent.anim.flipHoriz(flip)

    def processInput(self, pressed):
        """
        Stub method for processing input from the
        keyboard. Passes because some states may
        block input.
        @pressed : A sequence of booleans; one for each key.
        """
        pass
    
    def update(self):
        """
        Stub method for a frame-by-frame update. 
        Passes because some states may only process 
        input without updating.
        """
        pass
    
class StandingState(PlayerState):
    """
    State for when the player is standing still.
    """
    def __init__(self, parent, flip=False):
        """
        Initialize and set the horizontal speed
        to be still.
        @parent : Reference to the player object.
        @flip : Horizontal flip for the animation
        as a boolean.
        """
        super().__init__(parent, "stand", flip)
        self.parent.kinem.vel_x = 0
        self.parent.kinem.vel_y = 0

    def processInput(self, pressed):
        """
        If left is pressed, the player should begin
        running to the left (non-flipped is facing
        right so flip equals True here). Otherwise
        if right is pressed, begin running to the
        right.
        @pressed : A sequence of booleans; one for each key.
        """
        if pressed[keys.K_LEFT]:
            return RunningState(self.parent, flip=True)
        if pressed[keys.K_RIGHT]:
            return RunningState(self.parent, flip=False)
        if pressed[keys.K_SPACE]:
            return JumpingState(self.parent, jump=True)
        
    
class RunningState(PlayerState):
    """
    State for when the player is running along the ground.
    """
    def __init__(self, parent, flip=False):
        """
        Initialize and set the horizontal speed
        to be moving in the appropriate direction.
        @parent : Reference to the player object.
        @flip : Horizontal direction for the animation
        and movement as a boolean. True for right, False
        for left.
        """
        super().__init__(parent, "run", flip)
        self.parent.kinem.vel_x = -5 if flip else 5

    def processInput(self, pressed):
        """
        If moving left and left key is released, switch
        to standing still. Else if moving right and right
        key is released, switch to standing still.
        @pressed : A sequence of booleans; one for each key.
        """
        if self.flip and not pressed[keys.K_LEFT]:
            return StandingState(self.parent, self.flip)
        if not self.flip and not pressed[keys.K_RIGHT]:
            return StandingState(self.parent, self.flip)
#I would recomend using 3 states having a single jump second jump and falling state but you could do this all in 1 state or just a jumping and falling state
# for all the states you make I would recomend using having an update method this will run at all times
# I would also recomend having a process input method to execute any code for keys that are pressed
# and also have an init method that you can model after the other states that are given to you 
# you should also pass flip in as well it just makes the animations work a lot nicer
class JumpingState(PlayerState):
    def __init__(self, parent, jump=False):
        super().__init__(parent, "jump", jump)
        if jump:
            self.parent.kinem.vel_y = -10
        else:
            self.parent.kinem.vel_y = 0
    def update(self):
        pass
        #do any animation changes that you need to do like using the flip method  self.parent.anim.flipHoriz(self.parent.flip)
        #also would recomend cheking if velocity is zero to enter change animation to falling
        #since update is also running at all times this should be the method that returns you to standing when the correct conditions are met 

    def processInput(self, pressed):
        pass
        #same as the process input before just instead of returning to a state just changing velocity and flip accordingly