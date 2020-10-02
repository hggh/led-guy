use <hggh/mico_usb_breakout_holder.scad>


cube([14, 10, 5.1]);
translate([0, 14.5, 5.1 + 6]) { 
    rotate([180, 0, 0]) mico_usb_breakout_holder();
}