# Raw capture (named): CVOGHBBase_SetPartnerLink

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604db0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00604db0` |
| **Ghidra name** | `FUN_00604db0` |
| **Canonical name** | `CVOGHBBase_SetPartnerLink` |
| **System** | `object / combat-target / HB` |
| **Capture** | 2026-07-29 W20-S |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |

Authoritative body + byte seal: `docs/reconstruction/raw/aa_00604db0_FUN_00604db0.md`.

## ABI

```c
// __thiscall ECX=this HB, stack partner HB or null, ret 4
void CVOGHBBase_SetPartnerLink(void *thisHb, void *partnerHb);
// write this+0x24 if partner==null || partner+0x18 != this+0x18
```
