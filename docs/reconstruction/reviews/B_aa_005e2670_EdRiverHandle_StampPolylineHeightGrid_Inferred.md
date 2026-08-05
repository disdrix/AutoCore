# Review B (skeptical / adversarial): `aa_005e2670` EdRiverHandle_StampPolylineHeightGrid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e2670` |
| **VA** | `0x005e2670` |
| **Canonical name** | `EdRiverHandle_StampPolylineHeightGrid_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W36-D) |
| **Counterpart** | `reviews/A_aa_005e2670_EdRiverHandle_StampPolylineHeightGrid_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is `unaff_retaddr` really the return address? | **No** — used as map object (`+0x10/+0x18/+0x3e0`); stack depth places it at first stack formal |
| Is RET 0 (cdecl) or RET 0xC? | **No** — epilogue `C2 10 00` seals **RET 0x10** (4 stack dwords) |
| Is this a pure leaf math helper? | **No** — multi-vfunc worker + heap list + tile invalidate |
| Is `g_flLevelUpUiBase` a level-up UI constant here? | **Misnomer** — value is **2.0f** at `0xa10e74` (family-wide float 2) |
| Ghidra body end `005e29c7` | Inclusive-ish plate; exclusive end after `C2 10 00` is **`005e29c8`**, size **856** |
| Could name claim product “River” without evidence? | Family geo string + vtable neighborhood support **EdRiverHandle_*** Inferred; not PDB-confirmed |
| operator_delete “does not return”? | Decompiler false positive on free-loop |
| Is 00971030 related? | **No** — co-partition only; different subsystem |

---

## Residual risks

1. Product typename for host / map class.  
2. Exact blend formula in u16 requant (SSE min/max of influence lanes) — sealed constants, open micro-order.  
3. Nested stamp/tile helpers unowned.  
4. No live virtual call trace.

---

## Minimal sealed model

```
EdRiverHandle_StampPolylineHeightGrid(host@ECX, map, A, B, C):
  node = host.vt[+0xb8](); if !node return
  node.vt[+0xb4](1)
  list = CircularSentinel_Alloc0x14()
  walk chain:
    clear list; node.vt[+0xbc](list, cell*2)
    for consecutive list nodes: sample + 006442c0; union bbox
    next via +0x14/+0x24; stop on cycle/null
  requant u16 grid in bbox (1/65536, clamp, *65535, round)
  004a8d40(map, bbox±2)
  release chain vt[+0x70](1,0); free list
  ret 10
```

---

## Verdict

Do not collapse to decompiler 3-arg void plate. ABI + stages sealed. **accept-with-gaps**.
