# Function record: AnimEventVec_InsertN_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004501d0` |
| **Canonical name** | `AnimEventVec_InsertN_Inferred` |
| **Ghidra name** | `FUN_004501d0` |
| **Address** | `0x004501d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / animation events |
| **Wave** | W34-O OWN-ONLY dual |
| **Completion status** | **Reviewed** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

`vector<AnimEventElem>::insert(where, count, value)` for this binary’s **0x1c** anim-event element (vtbl `PTR_FUN_009d4828`, nested pointer/dword range at `+0xc`). Structural domain from scaffold `anmAnimEvent` / `anmAnimEventsImpl` call chain and element construct/assign helpers. **Not** `basic_string` insert (`StdVector_InsertN_BasicString` @ `0x004306b0` — different ABI and element helpers).

## Signature

```c
// 4 stack args; callee cleans 0x10; void
void AnimEventVec_InsertN_Inferred(void *vec, void *where, uint32_t count, void *value);
```

## Artifacts

See `aa_004501d0_FUN_004501d0.md` for full paths. Twin clean: `AnimEventVec_InsertN_Inferred.cpp`.

## Related

- Size helper: `StdVector_Elem28_Size` (`0x00469c50`, W33-J)
- Resize parent: `FUN_00450050` (unowned)
- Contrast string insert: `StdVector_InsertN_BasicString` (`0x004306b0`, W32-B) — thiscall + `RET 0x0C`
- Nested free: uninit_copy `FUN_00450600`, fill `FUN_00450560`, destroy `FUN_004501a0`, assign `FUN_0044ffa0`, nested-range copy `FUN_00444100`
