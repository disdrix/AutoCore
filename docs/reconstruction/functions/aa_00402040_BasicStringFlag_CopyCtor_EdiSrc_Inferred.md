# Function record: BasicStringFlag_CopyCtor_EdiSrc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402040` |
| **Canonical name** | `BasicStringFlag_CopyCtor_EdiSrc_Inferred` |
| **Ghidra name** | `FUN_00402040` |
| **Address** | `0x00402040`–`0x0040208c` inclusive (**77 B** / `0x4D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression (partition parent); unit = shared aggregate copy-ctor |
| **Completion status** | **Dual sealed MEGA-080** |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |
| **Verdict** | **accept-with-gaps** |

## Purpose

SEH-guarded **copy constructor** for:

```text
struct BasicStringFlag {
  std::basic_string<char> str;  // +0x00, size 0x1c
  uint8_t flag;                 // +0x1c
};
```

## Signature (sealed)

```c
// dest on stack; source in EDI; returns dest in EAX; RET 4
BasicStringFlag* __stdcall /* + EDI src */
BasicStringFlag_CopyCtor_EdiSrc_Inferred(BasicStringFlag* dest);
```

## Evidence summary

- Live decompile ≡ raw 2026-07-23.
- Disasm: `PUSH EDI; MOV ECX,ESI; CALL [0x009c62ec]`; `MOV AL,[EDI+0x1c]; MOV [ESI+0x1c],AL`; `RET 4`.
- Callers: 2 UNCONDITIONAL_CALL (`00401fe0`, `00980160`).
- Twin construct-from-parts: `FUN_00401d30` (not dualled here).

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00402040_FUN_00402040.md` |
| Annotated | `docs/reconstruction/raw/aa_00402040_FUN_00402040.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicStringFlag_CopyCtor_EdiSrc_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00402040.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00402040_FUN_00402040.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00402040_BasicStringFlag_CopyCtor_EdiSrc_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00402040_BasicStringFlag_CopyCtor_EdiSrc_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00402040-mega-080-report.md` |

## Gaps

1. Product English for flag byte.
2. Full value_type / map product name for parent `FUN_00401fe0`.
3. Runtime / bit-exact / differential.

## Port note (AutoCore)

Port as copy of a string+byte aggregate (or `pair<string,char>`-shaped). Preserve **EDI source** call convention at native call sites, or lower to an explicit two-pointer API in managed code. Do **not** treat as mission-dialog UI logic.
