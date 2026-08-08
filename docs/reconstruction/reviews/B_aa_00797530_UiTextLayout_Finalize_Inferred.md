# Review B (skeptical / adversarial): `aa_00797530` UiTextLayout_Finalize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00797530` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-122) |
| **Counterpart** | `reviews/A_aa_00797530_UiTextLayout_Finalize_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete dtor of the layout block | **Falsified** — no free of vectors/host; dualed `00797d70` **calls** this then frees |
| 2 | thiscall ECX this | **Falsified** — body uses **EBX** (`LEA EDI,[EBX+0xC]`); callers `MOV EBX, layout` |
| 3 | cdecl 0-arg / bare RET | **Falsified** — terminal **`C2 04 00`** (`RET 4`); stack flag consumed |
| 4 | Packet / Client_RecvBroadcast helper | **Falsified** — wstring/UI metrics/run vectors only; scaffold parent seed false |
| 5 | Always computes mode-3 line height | **Falsified** — gated on `flag == 0`; dtor/wrappers pass **1** |
| 6 | Frees host or run vectors | **Falsified** — no `operator_delete` in body; only materialize + clear text |
| 7 | Half-factor is unknown magic | **Falsified** — `DAT_00a0f298` bytes `0000003f` = **0.5f** |
| 8 | Product demangle sealed without RTTI | **Open gap** — no type_info; `_Inferred` retained (not a reject) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Finalize vs dtor role | **High** | Wrong teardown order / double-free |
| EBX-this + RET 4 | **High** | Stack corruption / wrong this |
| Mode-3 flag gate | **High** | Bad line-height on dtor path |
| Offset map | **High** | Wrong field writes |
| Product demangle | **Open** | Name residual only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
// FUN_00797530:
// SEH LAB_009add2c; EBX = layout
// trim trailing L' ' on wstring @ +0x0C
// align x by mode @ +0xCC (1 half, 2 full, 3 lineH if flag==0)
// multi-run (stride 0x60) → display runs (stride 0x80) OR single-run + FUN_00427050
// y += float@+0xAC; ready@+0xB4=1; resize(0); FUN_00427210(0)
// RET 4
```

Live decompile 2026-08-05 ≡ scaffold/raw CF.  
Epilogue hex seals `RET 4`.  
Caller sample dualed complete dtor: `MOV EBX,ESI; … CALL FUN_00797530` after metrics merge with flag **1**.  
`FUN_00797e20` also calls with flag **0** at two sites (mode-3 height path).

---

## 4. Surviving contract for AutoCore

```
// Port finalize only (not dtor):
// Machine: EBX = layout*; stack flag; RET 4
void UiTextLayout_Finalize_Inferred(char flag) {
  // trim spaces; align; materialize runs; mark ready; clear text
}
// Complete dtor path:
//   merge float@+0xA4/+0xA8; EBX=layout; Finalize(1); free vectors; ~wstring
// Do NOT free layout or run buffers inside Finalize.
```

---

## 5. Verdict

**accept-with-gaps** — adversarial claims against dtor-merge, ECX-thiscall, bare-RET, packet role, always-mode3, and host-free are **falsified**. Product English remains open → `_Inferred` retained. Terminal false.
