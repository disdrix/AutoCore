# Function record: TNL_NetClassRepInstance_Dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2470` |
| **Canonical name** | `TNL_NetClassRepInstance_Dtor` |
| **Ghidra name** | `FUN_005a2470` |
| **Address** | `0x005a2470` |
| **Body span** | `005a2470`–`005a248e` exclusive (**30** B through plain `ret`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `tnl` / NetClassRep |
| **Completion status** | **Dual A/B sealed** (W26-R 2026-07-29) — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005a2470_TNL_NetClassRepInstance_Dtor.md`, `reviews/B_aa_005a2470_TNL_NetClassRepInstance_Dtor.md` |

## Alias

- Scaffold: `FUN_005a2470`
- Referenced from W21-K ctor dual / W25-I atexit dual as ClassRep dtor

## Purpose

In-place destructor complementary to `TNL_NetClassRepInstance_Ctor` (`FUN_005a2410`):

1. Install NetClassRepInstance vtbl `PTR_FUN_009d7bf4`.
2. `free` heap class name at `+0x20` (from ctor `_strdup`).
3. Restore base ClassRep vtbl `PTR_LAB_009d7af4`.

Does **not** `operator_delete` the object (scalar deleting wrapper `FUN_005a2730` does when bit0 set). Does **not** remove from `DAT_00d179a4` ClassList.

## Signature

```c
void __fastcall TNL_NetClassRepInstance_Dtor(NetClassRepInstance* self);
// plain ret
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005a2470_FUN_005a2470.md`
- Annotated: `docs/reconstruction/raw/aa_005a2470_FUN_005a2470.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/TNL_NetClassRepInstance_Dtor.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_005a2470.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_005a2470_FUN_005a2470.md`
- Sibling ctor: `docs/reconstruction/functions/aa_005a2410_TNL_NetClassRepInstance_Ctor.md`
- Atexit caller dual: `docs/reconstruction/functions/aa_009c3de0_FUN_009c3de0.md`

## Callers / callees

**Callees:** `free` (IAT `0x009c6524`).

**Callers:**

| Site | Role |
|---|---|
| `FUN_009c3de0` @ `0x009c3de5` | atexit: `mov ecx, 0x00b04f40; jmp` this |
| `FUN_005a2730` @ `0x005a2733` | scalar deleting: call this; optional `operator_delete` |

**Globals:** vtbls `0x009d7bf4`, `0x009d7af4`.

## Confidence

| Claim | Level |
|---|---|
| Body bytes / free / vtbl restore | **Confirmed** |
| Pair with NetClassRepInstance ctor | **High** |
| Product name NetClassRepInstance dtor | **High** (RTTI/ctor dual lineage; not pure invention) |
| ClassList unlink elsewhere | **Open** (not this VA) |

## Dual verdict

**accept**
