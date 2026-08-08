# Function record: Mem_ZeroSixDwords_Ecx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416370` |
| **Canonical name** | `Mem_ZeroSixDwords_Ecx_Inferred` |
| **Ghidra name** | `FUN_00416370` |
| **Address** | `0x00416370`–`0x00416388` exclusive (**24 B** / `0x18`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / memory (six-dword / 0x18-byte zero) |
| **Classification** | leaf |
| **Calling convention** | **ECX** = `uint32_t*` dest; **EAX** = dest; **`ret 0`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9I-I 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00416370_Mem_ZeroSixDwords_Ecx_Inferred.md` |
| **Dual B** | `reviews/B_aa_00416370_Mem_ZeroSixDwords_Ecx_Inferred.md` |
| **Name confidence** | Inferred (structural; sole-caller CS size evidence) |
| **Last reviewed** | `2026-08-04` (WQ9I-I) |

## Alias

- Ghidra: `FUN_00416370`
- Prior scaffold: partial raw/annotated/clean only
- Reject: thiscall product method without evidence; `RtlZeroMemory` CRT demangle without PDB; skill/domain names

## Purpose

Zero **six** consecutive dwords at the destination pointer (**0x18** bytes — Win32 x86 `sizeof(CRITICAL_SECTION)`). Sole call site pre-zeros the CS-shaped field at outer-object `+0x18` before `CriticalSection_Initialize_SehToHresult_Ecx_Inferred`.

## Signature

```c
uint32_t *Mem_ZeroSixDwords_Ecx_Inferred(/*ECX*/ uint32_t *dest);
/* ret 0; EAX = dest */
```

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers** | `FUN_00489d95` @ `0x00489d9b` — `MOV ESI,ECX`; `LEA ECX,[ESI+0x18]`; CALL |
| **Pair** | `CriticalSection_Initialize_SehToHresult_Ecx_Inferred` (`0x00416390`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00416370_FUN_00416370.md`
- Annotated: `docs/reconstruction/raw/aa_00416370_FUN_00416370.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Mem_ZeroSixDwords_Ecx_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00416370.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00416370_FUN_00416370.md`
- Report: `docs/agents/task-dual-ab-00416370-00416390-wq9ii-report.md`

## Confidence

| Claim | Level |
|---|---|
| Body + ret 0 + ECX/EAX ABI | **High** |
| Six-dword / 0x18 zero CF | **High** |
| Sole-caller CS-field role | **High** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
