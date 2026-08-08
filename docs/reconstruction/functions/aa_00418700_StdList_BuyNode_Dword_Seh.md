# Function record: StdList_BuyNode_Dword_Seh

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418700` |
| **Canonical name** | `StdList_BuyNode_Dword_Seh` |
| **Ghidra name** | `FUN_00418700` |
| **Address** | `0x00418700`–`0x00418779` inclusive (**122 B** / `0x7A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared MSVC `std::list` dword `_Buynode` (SEH-framed) |
| **Dual verdict** | A **accept** / B **accept** (MEGA-081 2026-08-05) |
| **Terminal** | **false** (runtime open) |

## Purpose

SEH-framed list node buyer:

```text
node = operator_new(0xC)
if node:
  node[0] = link0
  node[1] = link1
  node[2] = *pValue
return node   // EAX; stdcall ret 12
```

## Signature

```c
void *StdList_BuyNode_Dword_Seh(void *link0, void *link1, uint32_t *pValue);
```

## Family

| Peer | VA | Note |
|---|---|---|
| `StdList_BuyNode_Dword` | `0x006759b0` | dualed W20-M; same fill; **no** SEH |
| Incsize `"list<T> too long"` | `0x00404840` | caller size++ |
| Insert wrappers | `0x00402d10`, `0x004040f0`, `0x00517db0`, … | buy + incsize + relink |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00418700_FUN_00418700.md` |
| Annotated | `docs/reconstruction/raw/aa_00418700_FUN_00418700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_BuyNode_Dword_Seh.cpp` |
| FUN twin | `docs/reconstruction/reconstructed-exact/FUN_00418700.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00418700_StdList_BuyNode_Dword_Seh.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00418700_StdList_BuyNode_Dword_Seh.md` |
| FUN record | `docs/reconstruction/functions/aa_00418700_FUN_00418700.md` |
| Report | `docs/agents/task-dual-ab-00418700-mega-081-report.md` |

## Port notes

- Port as **`std::list` `_Buynode`** for **dword** payload (node **0xC**).
- **`__stdcall` RET 0xC**; return pointer in **EAX**.
- Keep distinct from non-SEH twin `0x006759b0` and from tree Buynode / isnil families.
- Callers own Incsize + circular link rewiring.
