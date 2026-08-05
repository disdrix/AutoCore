# Annotated low-level: FUN_0044fee0 → NestedHash0x10_StaticOnceGet_d1fcc0_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0044fee0` |
| VA | `0x0044fee0`–`0x0044ff39` (**90 B**) |
| System | NestedHash static once-get (sentinel node 0x10 family) |
| Date | 2026-07-29 (W35-E dual seal) |
| Ghidra | `FUN_0044fee0` |
| Named | `NestedHash0x10_StaticOnceGet_d1fcc0_Inferred` |

---

## Machine-level notes

- Source: raw capture + live re-verify W35-E.
- Prefer bytes when decompiler conflicts (none material here).
- **ABI:** no stack args; returns pointer to static NestedHash shell; plain **`RET`**.
- **Once-flag:** `DAT_00d1fce8` bit 0 guards one-shot init.
- **Placement target:** `DAT_00d1fcc0` — NestedHash span **0x28** (W34-E layout).
- **Ctor:** sealed `NestedHash_Ctor_Sentinel0x10_Inferred` (`0x00457ac0`).
- **Teardown:** `_atexit(LAB_009c34b0)` registers static dtor (DATA xref to object).
- **Caller use:** `FUN_0044fe10` calls twice; second use compares `local` to `*(get()+8)` (sentinel) then virtual call — NestedHash bag lookup path, not animation-track product necessarily.

## Pseudocode (annotated)

```c
// NestedHash0x10_StaticOnceGet_d1fcc0_Inferred
// Returns: &DAT_00d1fcc0 (static NestedHash shell, node size 0x10)
void *NestedHash0x10_StaticOnceGet_d1fcc0_Inferred(void)
{
  // SEH frame LAB_009bca1d
  if ((DAT_00d1fce8 & 1) == 0) {
    DAT_00d1fce8 |= 1;
    NestedHash_Ctor_Sentinel0x10_Inferred(&DAT_00d1fcc0);  // FUN_00457ac0
    atexit(LAB_009c34b0);
  }
  return &DAT_00d1fcc0;
}
```

## Call graph

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_0044fe10` ×2 | NestedHash sentinel / lookup path |
| Callee | `FUN_00457ac0` | NestedHash0x10 placement ctor |
| Callee | `_atexit` | process teardown |
| Data | `DAT_00d1fcc0` | static NestedHash object |
| Data | `DAT_00d1fce8` | once flags dword |
| Data | `LAB_009c34b0` | atexit dtor thunk |

## Open questions

- Product/PDB English for this specific static instance (anmTrackEvents scaffold is untrusted).
- Full body of atexit dtor `LAB_009c34b0` (not owned).
- Runtime / bit-exact.
