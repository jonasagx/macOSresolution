//
//  main.cpp
//  resolution
//
//  Created by Jonas Xavier on 3/19/18.
//  Copyright © 2018 Jonas Xavier. All rights reserved.
//

#include <iostream>
#include <CoreGraphics/CoreGraphics.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    auto mainDisplayId = CGMainDisplayID();
    
    std::cout << "Current resolution was "
    << CGDisplayPixelsWide(mainDisplayId) << 'x'
    << CGDisplayPixelsHigh(mainDisplayId) << std::endl
    << "Supported resolution modes:";
    
    auto modes = CGDisplayCopyAllDisplayModes(mainDisplayId, nullptr);
    auto count = CFArrayGetCount(modes);
    CGDisplayModeRef mode = nullptr;
    for(auto c=count;c--;){
        mode = (CGDisplayModeRef)CFArrayGetValueAtIndex(modes, c);
        auto w = CGDisplayModeGetWidth(mode);
        auto h = CGDisplayModeGetHeight(mode);
        std::cout << std::endl << w << 'x' << h;
    }
    CGDisplaySetDisplayMode(mainDisplayId, mode, nullptr);
    std::cout << " is the selected top one." << std::endl;
    std::cin.get();
    return 0;
    
}



