//SBDeviceLockView - used to prompt users for their passcode. Useful in lock screen tweaks.


@class SBDeviceLockEntryField, SBDeviceLockTitle; //: UIView

@interface SBDeviceLockView : UIView
{
    int _style;
    int _interfaceOrientation;
    SBDeviceLockTitle *_statusView;
    SBDeviceLockEntryField *_entryView;
    id _delegate;
}
+ (int)defaultStyle;
+ (id)newWithStyle:(int)fp8 interfaceOrientation:(int)fp12 showsEmergencyCall:(BOOL)fp16; //Use this instead of initalizing your own. Usually should set showsEmergencyCall to FALSE.
- (id)_initWithStyle:(int)fp8 interfaceOrientation:(int)fp12 showsEmergencyCall:(BOOL)fp16;
- (BOOL)canBecomeFirstResponder;
- (BOOL)becomeFirstResponder;
- (BOOL)isFirstResponder;
- (BOOL)resignFirstResponder;
- (void)dealloc;
- (void)setUserInteractionEnabled:(BOOL)fp8;
- (id)statusView; //Top view, example usage: [[lockView statusView] setHidden:YES];
- (id)entryView; //View where you see input entered.
- (id)keypadView; //Self-explanatory.
- (id)statusTitle; //Pretty buggy, I recommend you just don't use this.
- (void)setStatusTitle:(id)fp8;
- (id)statusSubtitle;
- (void)setStatusSubtitle:(id)fp8;
- (BOOL)isShowingStatusWarning;
- (void)setShowingStatusWarning:(BOOL)fp8; //Use in cases such as incorrect passcode.
- (void)blinkStatusView; //^
- (id)passcode; //This is NOT the required passcode - it's the currently attempted pascode.
- (void)setPasscode:(id)fp8; //Example usage: set this to @"" in event of incorrect passcode.
- (BOOL)isShowingEntryStatusWarning;
- (void)setShowingEntryStatusWarning:(BOOL)fp8;
- (BOOL)playsKeyboardClicks;
- (void)setPlaysKeyboardClicks:(BOOL)fp8; //Please, NO.
- (BOOL)showsEmergencyCallButton;
- (void)setShowsEmergencyCallButton:(BOOL)fp8;
- (BOOL)isKeypadMinimized;
- (void)deviceLockEntryFieldDidAcceptEntry:(id)fp8;
- (void)deviceLockEntryFieldDidCancelEntry:(id)fp8;
- (BOOL)deviceLockEntryField:(id)fp8 shouldInsertText:(id)fp12;
- (void)deviceLockEntryFieldTextDidChange:(id)fp8;
- (void)notifyDelegateThatPasscodeDidChange;
- (void)notifyDelegateThatPasscodeWasEntered;
- (void)notifyDelegateThatCancelButtonWasPressed;
- (void)notifyDelegateThatEmergencyCallButtonWasPressed;
- (void)setInterfaceOrientation:(int)fp8;
- (void)willAnimateToInterfaceOrientation:(int)fp8;
- (void)animateToInterfaceInterfaceOrientation:(int)fp8;
- (void)didAnimateToInterfaceOrientation:(int)fp8;
- (id)delegate;
- (void)setDelegate:(id)fp8;
- (int)interfaceOrientation;
- (int)style;

@end

/*Delegate methods:

-(void)deviceLockViewPasscodeEntered:(SBDeviceLockView *)entered; //Fired when a passcode is entered and submitted. Grab passcode attempt using [entered passcode].
-(void)deviceLockViewCancelButtonPressed:(id)pressed; //Fired when cancel button is pressed.

*/