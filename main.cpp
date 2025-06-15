#include "Device.h"   
#include "Remote.h"   

// Display the menu for selecting a device
void showDeviceMenu() {
    cout << "\nSelect a device:\n";
    cout << "1. TV\n";
    cout << "2. Radio\n";
    cout << "3. Speaker\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}

// Display the menu for selecting a remote type
void showRemoteTypeMenu() {
    cout << "\nSelect a remote type:\n";
    cout << "1. Basic Remote\n";
    cout << "2. Voice Remote\n";
    cout << "3. Touch Remote\n";
    cout << "0. Back\n";
    cout << "Choice: ";
}

// Display menu options for Basic Remote
void showBasicRemoteMenu() {
    cout << "\nBasic Remote - Choose an action:\n";
    cout << "1. Toggle Power\n";
    cout << "2. Volume Up\n";
    cout << "3. Volume Down\n";
    cout << "4. Channel Up\n";
    cout << "5. Channel Down\n";
    cout << "6. Show Status\n";
    cout << "0. Back\n";
    cout << "Choice: ";
}

// Display menu options for Voice Remote
void showVoiceRemoteMenu() {
    cout << "\nVoice Remote - Say your command:\n";
    cout << "1. Say Command\n";
    cout << "0. Back\n";
    cout << "Choice: ";
}

// Display menu options for Touch Remote
void showTouchRemoteMenu() {
    cout << "\nTouch Remote - Choose a gesture:\n";
    cout << "1. Tap power button (Toggle Power)\n";
    cout << "2. Swipe up (Volume Up)\n";
    cout << "3. Swipe down (Volume Down)\n";
    cout << "4. Swipe right (Channel Up)\n";
    cout << "5. Swipe left (Channel Down)\n";
    cout << "6. Show Status\n";
    cout << "0. Back\n";
    cout << "Choice: ";
}

int main() {
    Device* device = nullptr; // Pointer to hold selected device
    Remote* remote = nullptr; // Pointer to hold selected remote

    while (true) {
        showDeviceMenu(); // Ask user to select a device
        int deviceChoice;
        cin >> deviceChoice;
        if (deviceChoice == 0) break; // Exit if choice is 0

        // Clean up previous device if any
        if (device != nullptr) {
            delete device;
            device = nullptr;
        }

        // Create selected device
        switch (deviceChoice) {
        case 1: device = new TV(); break;
        case 2: device = new Radio(); break;
        case 3: device = new Speaker(); break;
        default:
            cout << "Invalid device choice.\n";
            continue;
        }

        bool backToDeviceMenu = false;
        while (!backToDeviceMenu) {
            showRemoteTypeMenu(); // Ask user to select a remote type
            int remoteChoice;
            cin >> remoteChoice;
            if (remoteChoice == 0) {
                backToDeviceMenu = true;
                continue;
            }

            // Clean up previous remote if any
            if (remote != nullptr) {
                delete remote;
                remote = nullptr;
            }

            // Create selected remote type
            switch (remoteChoice) {
            case 1:
                remote = new Remote(device); // Basic remote
                break;
            case 2:
                remote = new VoiceRemote(device); // Voice remote
                break;
            case 3:
                remote = new TouchRemote(device); // Touch remote
                break;
            default:
                cout << "Invalid remote choice.\n";
                continue;
            }

            bool backToRemoteMenu = false;
            while (!backToRemoteMenu) {
                if (remoteChoice == 1) { // Menu for Basic Remote
                    showBasicRemoteMenu();
                    int action;
                    cin >> action;
                    switch (action) {
                    case 0: backToRemoteMenu = true; break;
                    case 1: remote->togglePower(); break;
                    case 2: remote->volumeUp(); break;
                    case 3: remote->volumeDown(); break;
                    case 4: remote->channelUp(); break;
                    case 5: remote->channelDown(); break;
                    case 6: remote->printStatus(); cout << endl; break;
                    default: cout << "Invalid action.\n";
                    }
                }
                else if (remoteChoice == 2) { // Menu for Voice Remote
                    showVoiceRemoteMenu();
                    int action;
                    cin >> action;
                    // Use dynamic_cast to safely cast to derived class
                    VoiceRemote* vr = dynamic_cast<VoiceRemote*>(remote);
                    if (!vr) {
                        cout << "Error casting to VoiceRemote.\n";
                        backToRemoteMenu = true;
                        continue;
                    }
                    switch (action) {
                    case 0: backToRemoteMenu = true; break;
                    case 1: {
                        cin.ignore(); // Clear input buffer
                        cout << "Enter voice command (volume up, volume down, power, channel up, channel down, status): ";
                        string command;
                        getline(cin, command); // Read full command
                        vr->sayCommand(command); // Pass to sayCommand function
                        break;
                    }
                    default: cout << "Invalid action.\n";
                    }
                }
                else if (remoteChoice == 3) { // Menu for Touch Remote
                    showTouchRemoteMenu();
                    int action;
                    cin >> action;
                    // Use dynamic_cast to safely cast to derived class
                    TouchRemote* tr = dynamic_cast<TouchRemote*>(remote);
                    if (!tr) {
                        cout << "Error casting to TouchRemote.\n";
                        backToRemoteMenu = true;
                        continue;
                    }
                    switch (action) {
                    case 0: backToRemoteMenu = true; break;
                    case 1: tr->togglePower(); break;
                    case 2: tr->volumeUp(); break;
                    case 3: tr->volumeDown(); break;
                    case 4: tr->channelUp(); break;
                    case 5: tr->channelDown(); break;
                    case 6: tr->printStatus(); cout << endl; break;
                    default: cout << "Invalid action.\n";
                    }
                }
            } // End remote control actions
        } // End remote type selection
    } // End device selection loop

    // Clean up memory before exiting
    if (remote) delete remote;
    if (device) delete device;

    cout << "Program exited.\n";
    return 0;
}
