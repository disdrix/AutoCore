# Function record: BasicStringFlag_CtorFromStringAndChar_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401d30` |
| **Canonical name** | `BasicStringFlag_CtorFromStringAndChar_Inferred` |
| **Ghidra name** | `FUN_00401d30` |
| **Address** | `0x00401d30`–`0x00401d83` inclusive (**84 B** / `0x54`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression (partition parent); unit = shared aggregate construct-from-parts |
| **Completion status** | **Dual sealed MEGA-065** |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |
| **Verdict** | **accept-with-gaps** |

## Purpose

SEH-guarded **construct-from-parts** constructor for:

```text
struct BasicStringFlag {
  std::basic_string<char> str;  // +0x00, size 0x1c
  uint8_t flag;                 // +0x1c
};
```

```text
BasicStringFlag_CtorFromStringAndChar_Inferred(dest, srcString, flagChar*)
  SEH install (LAB_009bbfb9)
  dest.str = *srcString          // IAT [0x009c62ec]
  dest.flag = *flagChar          // byte @ +0x1c
  return dest                    // EAX; RET 0xC
```

## Signature (sealed)

```c
// stack dest*, src string*, char*; EAX=dest; RET 0xC
BasicStringFlag* __stdcall BasicStringFlag_CtorFromStringAndChar_Inferred(
    BasicStringFlag* dest,
    const std::basic_string<char>* src,
    const uint8_t* flag_src);
```

## Evidence summary

- Live decompile ≡ raw 2026-07-23 CF; flag store ABI-corrected via disasm/bytes.
- Disasm: `CALL [0x009c62ec]`; `MOV DL,[ECX]; MOV [ESI+0x1c],DL`; `RET 0xC`.
- Callers: 1 UNCONDITIONAL_CALL (`FUN_00980160` @ `0x009801af`).
- Twin copy-ctor: dualed `BasicStringFlag_CopyCtor_EdiSrc_Inferred` `0x00402040` (MEGA-080).

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00401d30_FUN_00401d30.md` |
| Annotated | `docs/reconstruction/raw/aa_00401d30_FUN_00401d30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicStringFlag_CtorFromStringAndChar_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00401d30.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00401d30_FUN_00401d30.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00401d30_BasicStringFlag_CtorFromStringAndChar_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00401d30_BasicStringFlag_CtorFromStringAndChar_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00401d30-mega-065-report.md` |

## Related (not dualled here)

| VA | Role |
|---|---|
| `0x00402040` | Copy twin — dualed MEGA-080 |
| `0x004020f0` | string dtor only (flag POD) |
| `0x00401fe0` | node ctor embeds StringFlag at `+0xc` |
| `0x00980160` | sole caller (parse + insert parent) |
| `0x00401c50` | map insert/find peer after construct |

## Gaps

1. Product English for flag byte.
2. Full value_type / map product name for parent insert/node path.
3. Runtime / bit-exact / differential.

## Port note (AutoCore)

Port as construct of a string+byte aggregate (or `pair<string,char>`-shaped) from separate string and char sources. Preserve **RET 0xC** / three stack args at native sites, or lower to an ordinary managed constructor. Do **not** treat as mission-dialog UI logic. Keep distinct from copy twin `00402040` (EDI src, RET 4).
