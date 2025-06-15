#include "Device.h"

// === TV Class Implementation ===

// Return whether the TV is powered on
bool TV::isEnabled() const {
    return enabled;
}

// Power on the TV
void TV::enable() {
    enabled = true;
}

// Power off the TV
void TV::disable() {
    enabled = false;
}

// Return the current volume level
int TV::getVolume() const {
    return volume;
}

// Set volume with boundary checks
void TV::setVolume(int percent) {
    if (percent >= 0 && percent <= 100)
        volume = percent;
    else if (percent < 0)
        volume = 0;
    else
        volume = 100;
}

// Return the current channel
int TV::getChannel() const {
    return channel;
}

// Change the TV to a specific channel
void TV::setChannel(int ch) {
    if (ch > 0)
        channel = ch;
    else 
        volume = 1;
}

// Print current status of the TV
void TV::printStatus() const {
    cout << "[TV] Power: " << (enabled ? "ON" : "OFF")
        << ", Volume: " << volume
        << ", Channel: " << channel;
}



// === Radio Class Implementation ===

// Return whether the Radio is powered on
bool Radio::isEnabled() const {
    return enabled;
}

// Power on the Radio
void Radio::enable() {
    enabled = true;
}

// Power off the Radio
void Radio::disable() {
    enabled = false;
}

// Return current volume level
int Radio::getVolume() const {
    return volume;
}

// Set volume to a specific level with bounds checking
void Radio::setVolume(int percent) {
    if (percent >= 0 && percent <= 100)
        volume = percent;
    else if (percent < 0)
        volume = 0;
    else
        volume = 100;
}


// Return current frequency/channel
int Radio::getChannel() const {
    return channel;
}

// Set Radio frequency (represented as a channel here)
void Radio::setChannel(int ch) {
    if (ch > 0)
        channel = ch;
    else
        volume = 1;
}

// Print current status of the Radio
void Radio::printStatus() const {
    cout << "[Radio] Power: " << (enabled ? "ON" : "OFF")
        << ", Volume: " << volume
        << ", Frequency: " << channel << " MHz";
}



// === Speaker Class Implementation ===

// Return whether the Speaker is powered on
bool Speaker::isEnabled() const {
    return enabled;
}

// Power on the Speaker
void Speaker::enable() {
    enabled = true;
}

// Power off the Speaker
void Speaker::disable() {
    enabled = false;
}

// Return current volume level
int Speaker::getVolume() const {
    return volume;
}

// Set volume to a specific level with bounds checking
void Speaker::setVolume(int percent) {
    if (percent >= 0 && percent <= 100)
        volume = percent;
    else if (percent < 0)
        volume = 0;
    else
        volume = 100;
}


// Speakers typically don’t support channels, return dummy value
int Speaker::getChannel() const {
    return -1;  // Indicates unsupported operation
}

// Ignore channel change for speakers
void Speaker::setChannel(int ch) {
    cout << "[Speaker] Channel operation not supported.\n";
}

// Print current status of the Speaker
void Speaker::printStatus() const {
    cout << "Speaker is " << (enabled ? "On" : "Off")
        << ", Volume: " << volume;
}
