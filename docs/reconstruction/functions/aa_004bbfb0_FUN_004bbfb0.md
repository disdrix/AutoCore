# Function record: FUN_004bbfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbfb0` |
| **Canonical name** | `COList_Constructor` |
| **Ghidra name** | `FUN_004bbfb0` |
| **Address** | `0x004bbfb0`–`0x004bc17f` (**464 B / `0x1D0`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / COList |
| **Completion status** | **Human-refined** + dual A/B **accept-with-gaps** 2026-07-29 (W27-L) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004bbfb0_COList_Constructor.md`, `reviews/B_aa_004bbfb0_COList_Constructor.md` |
| **Last reviewed** | `2026-07-29` (W27-L) |

## Alias

- Ghidra: `FUN_004bbfb0`
- Named: `COList_Constructor`
- Prior scaffold: `Named_CalleeOf_Named_Client_InitInstance_004bbfb0`

## Purpose

Construct a **COList** host (`sizeof 0x58`): install vtbl, clamp capacities, build optional dual hashes + fixed third table, construct three 0x2C CS-list members, zero buffer triples. Published as `DAT_00b04830` from `Client_InitInstance`.

## Signature (sealed)

```c
// Machine: __thiscall, ECX=this, stack (capA, capB), ret 8, returns this*
COList* __thiscall COList_Constructor(COList* self, int capA, int capB);
// Ghidra: undefined4 * __thiscall FUN_004bbfb0(undefined4 *param_1, int param_2, int param_3)
```

| Item | Evidence | Conf |
|---|---|---|
| Body size 464 B | `get_function_by_address` 004bbfb0–004bc17f | **High** |
| ret 8 | exit `C2 08 00` | **High** |
| vtbl 009cb448 | entry `C7 06 48 B4 9C 00` | **High** |
| sizeof 0x58 | InitInstance `push 0x58` + `operator_new` | **High** |
| ctor args (5,10) | call site `6A 0A 6A 05` | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bbfb0_FUN_004bbfb0.md` (+ W27-L append)
- Annotated: `docs/reconstruction/raw/aa_004bbfb0_FUN_004bbfb0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/COList_Constructor.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004bbfb0.cpp`
- Named record: `docs/reconstruction/functions/aa_004bbfb0_COList_Constructor.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Caller** | `FUN_0094a6a0` / `Client_InitInstance` @ `0x0094a7eb` only |
| **Callees** | `operator_new`, `FUN_004bcf90`, `FUN_004bce90`, `InitializeCriticalSection` |

## Related

- `aa_004bbc70` COList_Destructor
- `aa_004bd1b0` COList_ScalarDeletingDestructor
- Nested hash ctors `FUN_004bcf90` / `FUN_004bce90` (not OWN this wave)

## Confidence

| Claim | Level |
|---|---|
| ABI / vtbl / sizeof / InitInstance args / CF stages | **High** |
| Nested hash product English | **Partial** |
| 0x2C list product name vs dual-CS ThreadSafeObjectList | **Partial** |
| Runtime / bit-exact | Open |
