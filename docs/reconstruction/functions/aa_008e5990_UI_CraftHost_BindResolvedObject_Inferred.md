# Function record: UI_CraftHost_BindResolvedObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e5990` |
| **Canonical name** | `UI_CraftHost_BindResolvedObject_Inferred` |
| **Ghidra name** | `FUN_008e5990` |
| **Address** | `0x008e5990`–`0x008e5cd0` inclusive (**833 B** / `0x341`) |
| **Module** | `autoassault.exe` |
| **System** | `inventory-transfer` |
| **Dual** | MEGA-032 2026-08-05 — **accept-with-gaps** |

## Evidence for name

1. Sole parent dualed as `Client_UI_CraftHost_BindObjectByTfid_Inferred` (`0x008e5ce0`) — resolves TFID then calls this with object* or null.
2. Body stores `host+0x7cc`, rebuilds name chrome (`operator_new(0x14c)` + `FUN_00764030`), appends `".geo"`, attaches via `host+0x520`, fills five recipe slots @ `+0x61c` — craft/RE panel bind of an **already resolved** object.
3. Partition hint: `UI_CraftHost_BindResolvedObject`.
4. Not a TFID resolver (that is the parent).

`_Inferred`: host class product name not RTTI-sealed in this unit.

## Signature (sealed)

```c
// thiscall; RET 4
void __thiscall UI_CraftHost_BindResolvedObject_Inferred(void *host, int *object_or_null);
```

## Key offsets

| Offset | Role |
|---|---|
| `host+0x520` | attach root widget |
| `host+0x530` / `+0x54c` | selection show/hide widgets |
| `host+0x568` / `+0x590` | 5 material slot widgets / TFID pairs |
| `host+0x61c` | 5 recipe slot rows (stride `0x14`) |
| `host+0x754` | preview (vtbl+`0x448`) |
| `host+0x7cc` | bound object* |
| `host+0x7d0` | name/chrome widget* (size `0x14c`) |
| `host+0x7da` | status / recipe-ready flag byte |

## Cross-links

- Parent TFID resolve (dualed): `Client_UI_CraftHost_BindObjectByTfid_Inferred` @ `0x008e5ce0`
- Other callers (residual): `FUN_008e6b50` @ `0x008e6b50`, `FUN_0093a330` @ `0x0093a330`
- Ghidra twin record: `aa_008e5990_FUN_008e5990.md`

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008e5990_FUN_008e5990.md` |
| Annotated | `docs/reconstruction/raw/aa_008e5990_FUN_008e5990.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_CraftHost_BindResolvedObject_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008e5990.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_008e5990_UI_CraftHost_BindResolvedObject_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_008e5990_UI_CraftHost_BindResolvedObject_Inferred.md` |
| Report | `docs/agents/task-dual-ab-008e5990-mega-032-report.md` |

## Gaps

- Product demangle for host/chrome classes.
- Residual helper English (not OWN).
- Runtime / bit-exact / differential.
