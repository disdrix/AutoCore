# Function record: BasicStringFlag_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004020f0` |
| **Canonical name** | `BasicStringFlag_Dtor_Inferred` |
| **Ghidra name** | `FUN_004020f0` |
| **Address** | `0x004020f0`–`0x00402126` inclusive (**55 B** / `0x37`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression (partition parent); unit = shared aggregate dtor (string only) |
| **Completion status** | **Dual sealed R10-018** |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |
| **Verdict** | **accept-with-gaps** |

## Purpose

SEH-guarded **destructor** for:

```text
struct BasicStringFlag {
  std::basic_string<char> str;  // +0x00, size 0x1c
  uint8_t flag;                 // +0x1c  (POD)
};
```

```text
BasicStringFlag_Dtor_Inferred(obj)
  SEH install (LAB_009bbfb9)
  ~obj.str                     // IAT [0x009c62f4]
  // flag: no work
  RET 4
```

## Signature (sealed)

```c
// stack object*; nested thiscall into string dtor; void; RET 4
void __stdcall BasicStringFlag_Dtor_Inferred(BasicStringFlag* obj);
```

## Evidence summary

- Live decompile ≡ raw 2026-07-23 CF; ABI sealed via `disassemble_function` + `read_memory`.
- Disasm: `MOV ECX,[ESP+0x10]`; `CALL [0x009c62f4]`; `RET 0x4`.
- Callers: 7 UNCONDITIONAL_CALL — all `Unwind@*`.
- Family twins: dualed `BasicStringFlag_CtorFromStringAndChar_Inferred` `0x00401d30` (MEGA-065); dualed `BasicStringFlag_CopyCtor_EdiSrc_Inferred` `0x00402040` (MEGA-080).

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004020f0_FUN_004020f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004020f0_FUN_004020f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicStringFlag_Dtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004020f0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_004020f0_FUN_004020f0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_004020f0_BasicStringFlag_Dtor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004020f0_BasicStringFlag_Dtor_Inferred.md` |
| Report | `docs/agents/task-dual-ab-004020f0-r10-report.md` |

## Related (not dualled here)

| VA | Role |
|---|---|
| `0x00401d30` | Ctor twin — dualed MEGA-065 |
| `0x00402040` | Copy twin — dualed MEGA-080 |
| `0x00401fe0` | node ctor embeds StringFlag at `+0xc` |
| `0x00980160` | parse/insert parent of ctor/copy path |

## Gaps

1. Product English for flag byte.
2. Per-Unwind owning frame product type.
3. Runtime / bit-exact / differential.

## Port note (AutoCore)

Port as **string field dispose only** for `{string, byte}`. Native sites use stack object* + **RET 4** (Unwind handlers). Managed code drops/disposes the string; ignore flag cleanup. Do **not** implement as mission-dialog logic. Keep distinct from ctor `00401d30` and copy `00402040`.
