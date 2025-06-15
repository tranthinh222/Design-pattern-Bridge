#include "Remote.h"

// Toggles the power state of the connected device
void Remote::togglePower() {
    if (device->isEnabled()) {
        device->disable();  // Turn off if currently enabled
    }
    else {
        device->enable();   // Turn on if currently disabled
    }
}

// Increases the device volume by 5 units
void Remote::volumeUp() {
    device->setVolume(device->getVolume() + 5);
}

// Decreases the device volume by 5 units
void Remote::volumeDown() {
    device->setVolume(device->getVolume() - 5);
}

// Increments the device channel by 1
void Remote::channelUp() {
    device->setChannel(device->getChannel() + 1);
}

// Decrements the device channel by 1
void Remote::channelDown() {
    device->setChannel(device->getChannel() - 1);
}

// Displays the current status of the device
void Remote::printStatus() {
    device->printStatus();
    cout << endl;
}


// VoiceRemote Implementation

// Interprets and executes a voice command
void VoiceRemote::sayCommand(const string& command) {
    cout << "[Voice Remote] You said: \"" << command << "\"\n";

    if (command == "volume up") {
        Remote::volumeUp();
        cout << "[Voice Remote] Volume increased.\n";
    }
    else if (command == "volume down") {
        Remote::volumeDown();
        cout << "[Voice Remote] Volume decreased.\n";
    }
    else if (command == "power") {
        Remote::togglePower();
        cout << "[Voice Remote] Power toggled.\n";
    }
    else if (command == "channel up") {
        Remote::channelUp();
        cout << "[Voice Remote] Channel increased.\n";
    }
    else if (command == "channel down") {
        Remote::channelDown();
        cout << "[Voice Remote] Channel decreased.\n";
    }
    else if (command == "status") {
        Remote::printStatus();
    }
    else {
        cout << "[Voice Remote] Unknown command.\n";
    }
}


// TouchRemote Implementation

// Swiping up gesture increases volume
void TouchRemote::volumeUp() {
    Remote::volumeUp();
    cout << "[Touch Remote] Swiped up - Volume increased.\n";
}

// Swiping down gesture decreases volume
void TouchRemote::volumeDown() {
    Remote::volumeDown();
    cout << "[Touch Remote] Swiped down - Volume decreased.\n";
}

// Swiping left gesture decreases channel
void TouchRemote::channelDown() {
    Remote::channelDown();
    cout << "[Touch Remote] Swiped left - Channel decreased.\n";
}

// Swiping right gesture increases channel
void TouchRemote::channelUp() {
    Remote::channelUp();
    cout << "[Touch Remote] Swiped right - Channel increased.\n";
}

// Tapping power button toggles power state
void TouchRemote::togglePower() {
    Remote::togglePower();
    cout << "[Touch Remote] Tapped power - Power toggled.\n";
}

// Displays the device status with a custom prefix
void TouchRemote::printStatus() {
    cout << "[Touch Remote] Device status:\n";
    Remote::printStatus();
    cout << endl;
}
