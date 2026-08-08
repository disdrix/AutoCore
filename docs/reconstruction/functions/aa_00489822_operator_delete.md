# Function record: operator_delete

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489822` |
| **Canonical name** | `operator_delete` |
| **Ghidra name** | `operator_delete` |
| **Address** | `0x00489822` |
| **Body** | `0x00489822`–`0x00489827` inclusive (**6 B** / `0x6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared CRT import thunk (`client::crt`) |
| **Agent** | R10-001 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept**) |
| **Terminal** | **false** |

## Purpose

MSVC IAT import thunk for scalar C++ `operator delete(void*)`:

1. Single instruction: `JMP dword ptr [0x009C6694]`
2. Loader-bound CRT free runs and **returns** to the original caller
3. Image-wide heap free entry (thousands of FUN + SEH Unwind callers)

Not an in-image free implementation. Not inventory-specific (partition parent `0x005725a0` is residual seed only).

## Signature

```c
// Machine: JMP [IAT 0x009C6694]; cdecl; void
void __cdecl operator_delete(void *block);
```

## Layout / IAT

| Address | Role |
|---|---|
| `0x00489822` | thunk body (`FF 25 94 66 9C 00`) |
| `0x009C6694` | IAT slot for scalar `operator_delete` |
| `0x0048981c` | sibling `operator_delete[]` thunk (IAT `0x009C6698`) — not this VA |
| `0x004898f4` | sibling C `free` import — not this VA |

## Call graph

| Role | Target |
|---|---|
| Static callees | none (indirect IAT JMP) |
| Dynamic target | CRT via `*0x009C6694` (live sample `0x006EA824` in this Ghidra image) |
| Callers | **5045** Ghidra callers (~2463 FUN/Catch + ~2568 Unwind); xref list capped at 100 |
| Sample | `FUN_00402280` (stdlist destroy free head), list/map tidy, scalar-deleting dtors, inventory free sites |

## Evidence summary

- Live decompile ≡ scaffold raw (artifact warnings preserved).
- Machine CF sealed only via `read_memory` + body range: 6-byte IAT JMP.
- Ghidra `noreturn` / jumptable / recursive-call narrative **rejected**.
- Name = CRT symbol; no `_Inferred`.

## Gaps

- CRT module/export identity behind IAT (runtime bind).
- Runtime / bit-exact / differential of free internals.
- Terminal Confirmed not claimed.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/operator_delete.cpp`
- Raw: `docs/reconstruction/raw/aa_00489822_operator_delete.md`
- Annotated: `docs/reconstruction/raw/aa_00489822_operator_delete.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00489822_operator_delete.md`
- Review B: `docs/reconstruction/reviews/B_aa_00489822_operator_delete.md`
- FUN record: `docs/reconstruction/functions/aa_00489822_FUN_00489822.md`
- Report: `docs/agents/task-dual-ab-00489822-r10-report.md`
