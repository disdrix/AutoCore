# Function record: Class_00a9bbe8_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416110` |
| **Canonical name** | `Class_00a9bbe8_CompleteDtor_Inferred` |
| **Ghidra name** | `FUN_00416110` |
| **Address** | `0x00416110` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / polymorphic class |
| **Wave** | WQ9I-G OWN-ONLY dual 2026-08-05 |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

## Purpose

MSVC-style **complete destructor** for the class with vftable at `0x00a9bbe8`. Body only stores the vptr (wrapped in SEH). Does not free the object — scalar-deleting wrapper `FUN_004160f0` owns optional `operator_delete`.

## Signature

```c
void Class_00a9bbe8_CompleteDtor_Inferred(void *obj /* stack */); // ret 4
```

## Vftable `0x00a9bbe8` (evidence)

| Slot | Target | Role |
|---|---|---|
| +0 | `0x00416150` | set `this+8` from stack |
| +4 | `0x0044f660` | get `*(this+8)` |
| +8 | `0x005ffc80` | empty |
| +0xC | `0x004320b0` | scalar-deleting style (inline vptr + free) |

## Dual A/B

| Path | Verdict |
|---|---|
| A fidelity | **accept-with-gaps** |
| B adversarial | **accept-with-gaps** |

## Artifacts

See `aa_00416110_FUN_00416110.md` for full path list.

## Gaps

- Product / RTTI class name
- Virtual dtor path dual (`0x004320b0`)
- Runtime / bit-exact
