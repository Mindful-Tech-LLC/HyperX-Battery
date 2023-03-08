# HyperX Cloud Flight 
  
| Vendor ID | Product ID |
| :---: | :---: |
| `0x0951` | `0x1723` |

| Triggers | Details |
| :---: | :---: |
| `0x21 0xff 0x05` | Get headset state. | 
 
| <b>State</b> | <b>Details</b> |
| :--- | :---: |
| `0x10` | `200` should be battery full, and `199` charging |
| `0xf` | Values from `130` to `0`.<br/>Essentially `100-70%`. |
| `0xe` | Values from `250` to `90`.<br/>Essentially `65-10%`. |
