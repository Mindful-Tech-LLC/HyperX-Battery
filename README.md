# HyperX Cloud Flight 

### Triggers
Sending `0x21 0xff 0x05` to the headset to get it's state.


### States
Battery has 3 states, `0x10`, `0xf` and `0xe`.

| <b>State</b> | <b>Details</b> |
| :--- | :---: |
| `0x10` | `200` should be battery full, and `199` charging |
| `0xf` | Values from `130` to `0`.<br/>Essentially `100-70%`. |
| `0xe` | Values from `250` to `90`.<br/>Essentially `65-10%`. |
