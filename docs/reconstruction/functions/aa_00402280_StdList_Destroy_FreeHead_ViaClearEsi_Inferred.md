# Function record: StdList_Destroy_FreeHead_ViaClearEsi_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402280` |
| **Canonical name** | `StdList_Destroy_FreeHead_ViaClearEsi_Inferred` |
| **Ghidra name** | `FUN_00402280` |
| **Address** | `0x00402280` |
| **Body** | `0x00402280`–`0x0040229c` inclusive (**29 B** / `0x1D`); pad `CC` before `FUN_004022a0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared `client::stdlist` |
| **Agent** | MEGA-067 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Complete destroy of an MSVC circular `std::list` shell:

1. `PUSH ESI; MOV ESI,ECX`
2. `StdList_Clear_ESI` (`0x00415e90`) — re-ring sentinel, size=0, free element nodes
3. `operator_delete(*(list+4))` — free sentinel
4. `*(list+4) = 0`
5. `POP ESI; RET`

Does **not** free the list shell object (stack local / embedded / array element).

## Signature

```c
// Machine: ECX = list*; bare RET; void
void __fastcall StdList_Destroy_FreeHead_ViaClearEsi_Inferred(StdListShell* list);
```

## Layout (list shell)

| Offset | Field |
|---|---|
| +0 | unused / allocator (untouched) |
| +4 | head / sentinel* |
| +8 | size (`_Mysize`) |

Shell size at `eh_vector` sites: **0xC**.

## Call graph

| Role | Target |
|---|---|
| Clear leaf | dualed `StdList_Clear_ESI` @ `0x00415e90` |
| Free | `operator_delete` @ `0x00489822` |
| Unwind callers | 10× `LEA ECX,local; JMP 00402280` |
| Structured | `FUN_008a5ba0` / `FUN_008a5c90` — `_eh_vector_*_iterator_(this+0x5cc, 0xC, 4, this)` |
| Ctor pair | `FUN_004023f0` (alloc empty sentinel via `0040fb90`) |
| Twin destroy (Clear-ECX) | `StdList_Destroy_FreeHead_Inferred` @ `0x00403430` |
| Family clone | `StdList_Destroy_FreeHead` @ `0x00497360` |

## Evidence summary

- Live decompile ≡ raw CF for clear+delete; **null head + epilogue** sealed only via `read_memory` (decomp false-noreturn).
- Twin outer CF with `00403430` (bytes differ only in clear CALL displacement).
- Mission Named_CalleeOf scaffold **retired** — shared stdlist util.

## Gaps

- Product demangle `list<T>` / element payload type.
- Host class English for `vtbl 00a4c61c` / `i_d_q.xml` parents (out of OWN).
- Runtime / bit-exact / differential.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdList_Destroy_FreeHead_ViaClearEsi_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00402280.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_00402280.cpp`
- Raw: `docs/reconstruction/raw/aa_00402280_FUN_00402280.md`
- Annotated: `docs/reconstruction/raw/aa_00402280_FUN_00402280.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00402280_StdList_Destroy_FreeHead_ViaClearEsi_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00402280_StdList_Destroy_FreeHead_ViaClearEsi_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_00402280_FUN_00402280.md`
- Report: `docs/agents/task-dual-ab-00402280-mega-067-report.md`
