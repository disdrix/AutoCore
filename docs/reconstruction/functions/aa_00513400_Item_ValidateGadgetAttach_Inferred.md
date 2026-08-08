# Function record: Item_ValidateGadgetAttach_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513400` |
| **Canonical name** | `Item_ValidateGadgetAttach_Inferred` (**Inferred** product English) |
| **Ghidra symbol** | `FUN_00513400` |
| **Address** | `0x00513400`–`0x005134d4` inclusive (**213 B** / `0xD5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body epilogue** | `RET 4` (`C2 04 00`) |
| **System** | `inventory-transfer` |
| **Partition** | MEGA-035 — parent dual `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` (`0x0085ce20`) |
| **Agent** | MEGA-035 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Validate whether a **gadget** may be attached to a **host item**:

1. **Type compatibility** — gadget template type (`…+0x4c4`) must match host type (`host+0xa8 → +0x38`), or special-case type **0x44** with subtype word **10**, or type **0x46** with subtype word **11**.
2. **Capacity** — host vtbl `+0x8c` used-count must not equal vtbl `+0x80` capacity.
3. **No duplicate** — no installed slot (vtbl `+0x7c(i)`) low-16 equals gadget id at ac-node `+0x34`.

Returns status codes for dualed hover mode-5 tooltip and apply-confirm dialog. **Does not mutate** inventory.

## Signature

```c
uint32_t __thiscall Item_ValidateGadgetAttach_Inferred(
    Item* host,     // ECX
    void* gadget);  // stack; CVOGGadget* after parent __RTDynamicCast
// RET 4
// 0 = allow | 1 = no slots | 2 = wrong type | 3 = duplicate
```

## Layout / offsets

| Access | Field |
|---|---|
| `host+0xa8` | component/def host |
| `hostComp+0x38` | item type id |
| `hostComp+0x3c` → `+0x3f4` | subtype word (exceptions) |
| gadget ac-chain → `+0x3c` → `+0x4c4` | gadget type id |
| gadget ac-chain → `+0x34` | gadget id (dup key, low 16) |
| vtbl `+0x8c` | used slot count (short) |
| vtbl `+0x80` | capacity |
| vtbl `+0x7c`(i) | installed id at slot |

## Call graph

| Role | Target |
|---|---|
| **Caller** | `FUN_00514190` @ `0x005141cc` |
| **Caller** | `FUN_0085ce20` @ `0x0085d0ee` (dualed; mode 5 + `CVOGGadget`) |
| **Caller** | `FUN_0085fa20` @ `0x0085fa49` (apply confirm) |
| **Xref** | `0x0085d6bb` (boundary unresolved) |
| **Callees** | leaf (virtual only) |
| **Sibling** | `FUN_00513c10` tinker-kit validator — **do not merge** (MEGA-036) |

## Evidence summary

- Live decompile ≡ raw CF; `RET 4` / ECX=item sealed via disasm + 4 call sites.
- Parent strings map codes 1/2/3 exactly; code 0 is allow path.
- Prior `Named_CalleeOf_*Tinkering*` scaffold **retired** (wrong parent string).

## Gaps

- Product/PDB demangle; vtbl English; type-id English for 0x44/0x46.
- Dual of apply callers; orphan xref function boundary.
- Runtime / bit-exact / differential.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/Item_ValidateGadgetAttach_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00513400.cpp`
- Retired: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00513400.cpp`
- Raw: `docs/reconstruction/raw/aa_00513400_FUN_00513400.md`
- Annotated: `docs/reconstruction/raw/aa_00513400_FUN_00513400.annotated.md`
- FUN record: `docs/reconstruction/functions/aa_00513400_FUN_00513400.md`
- Review A: `docs/reconstruction/reviews/A_aa_00513400_Item_ValidateGadgetAttach_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00513400_Item_ValidateGadgetAttach_Inferred.md`
- Report: `docs/agents/task-dual-ab-00513400-mega-035-report.md`
