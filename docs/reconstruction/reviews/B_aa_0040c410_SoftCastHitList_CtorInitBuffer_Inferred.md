# Review B (skeptical / adversarial): `aa_0040c410` SoftCastHitList_CtorInitBuffer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c410` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-111) |
| **Counterpart** | `reviews/A_aa_0040c410_SoftCastHitList_CtorInitBuffer_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Thiscall / ECX = this | **Falsified** — `MOV EAX,[ESP+0x14]`; no ECX object load; `RET 4` |
| 2 | Allocates heap hit buffer | **Falsified** — begin points at `self+0x20`; cap high-bit set; no CALL to allocator |
| 3 | Fills hits / performs soft-cast | **Falsified** — leaf stores only; fill is `FUN_0055e1e0` later in hub |
| 4 | Sorts hits | **Falsified** — sort is sibling `0x0048a060` (MEGA-116) |
| 5 | Skill / inventory / combat multi-hit list | **Falsified** — sole caller is interact hub `0x00925820`; shared SoftCastHitList layout with MEGA-116 |
| 6 | Capacity `0x80000008` means heap-owned 8 | **Falsified** — dtor `FUN_0040c510` frees only when `(int)cap >= 0`; high-bit skips free → inline sentinel |
| 7 | Decompiler `param_1[100]` is bug / wrong slot | **Falsified** — decimal 100 = dword index `0x64` = byte `0x190` = elem7+0x20; matches final `MOV [ECX+0x20],EDX` |
| 8 | Multiple callers / vtbl-only entry | **Falsified** — 1 UNCONDITIONAL_CALL xref @ `00925c06` |
| 9 | Runtime Confirmed / terminal | **Falsified** — no Launcher; terminal false by OWN rules |
| 10 | Product class name sealed without `_Inferred` | **Falsified** — no RTTI/demangle on unit; name is structural |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI stack-self / RET 4 | **High** | Wrong call convention port |
| Inline begin + cap high-bit | **High** | Double-free or leak in dtor port |
| Elem stride 0x30 × 8 seeds | **High** | Wrong buffer size / sort misalign |
| Sole hub caller role | **High** | Mis-system classification |
| Soft-cast product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

Live 2026-08-05 decompile **≡** raw 2026-07-23 CF. Disasm seals:

- `g_flOne` @ `0x00a0f2a0` = `3f800000`
- vtbl immediates `0x00a2f52c` / `0x00a2f538`
- capacity imm `08 00 00 80`
- epilog `C2 04 00`

Dtor twin free formula `(cap & 0x7fffffff) * 0x30` independently seals element size. Dualed sort sibling reads `+0x10`/`+0x14` exactly as this ctor writes.

---

## 4. Surviving contract for AutoCore

```
// Stack-construct soft-cast hit list (stdcall RET 4):
SoftCastHitList list; // or raw bytes ≥ 0x20 + 8*0x30
SoftCastHitList_CtorInitBuffer_Inferred(&list);
// then soft-cast fill, optional SoftCastHitList_SortIfCountGt1_Inferred(&list),
// walk hits, then dtor FUN_0040c510(&list).
// Do NOT treat as thiscall. Do NOT free inline buffer while cap high-bit set.
```

---

## 5. Verdict

Adversarial attacks on thiscall/heap-alloc/fill/sort/multi-caller/runtime claims fail. Residual product English only → **accept-with-gaps**. Terminal **false**.
