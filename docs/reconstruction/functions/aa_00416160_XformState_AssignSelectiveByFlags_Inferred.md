# Function record: XformState_AssignSelectiveByFlags_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416160` |
| **Canonical name** | `XformState_AssignSelectiveByFlags_Inferred` |
| **Ghidra name** | `FUN_00416160` |
| **Address** | `0x00416160` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | math / transform-state util |
| **Wave** | WQ9I-G OWN-ONLY dual 2026-08-05 |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

## Purpose

Assign transform-like state from **src** to **dest** with **per-block skip flags** at `+0xBC`. Two 64-byte matrix slots, mid always-block, optional tail vec3-sized block, and a dest-side generation counter.

## Signature

```c
void __thiscall XformState_AssignSelectiveByFlags_Inferred(
    XformState_Inferred *dest /* ECX */,
    const XformState_Inferred *src /* stack */); // ret 4
```

## Related (not OWN)

| VA | Role |
|---|---|
| `0x00416240` | Full assign: clear flags then call this |
| `0x00464850` | MI adjustor `this+0x10` → this |

## Dual A/B

| Path | Verdict |
|---|---|
| A fidelity | **accept-with-gaps** |
| B adversarial | **accept-with-gaps** |

## Artifacts

See `aa_00416160_FUN_00416160.md` for full path list.

## Gaps

- Product type / field English
- Flag bit product semantics
- Runtime / bit-exact
