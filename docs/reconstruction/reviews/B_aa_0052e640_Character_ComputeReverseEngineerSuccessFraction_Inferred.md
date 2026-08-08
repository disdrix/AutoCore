# Review B (adversarial): `aa_0052e640` Character_ComputeReverseEngineerSuccessFraction_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052e640` |
| **VA** | `0x0052e640`–`0x0052eb76` |
| **Canonical name** | `Character_ComputeReverseEngineerSuccessFraction_Inferred` |
| **Review date** | `2026-08-05` (MEGA-117 OWN dual) |
| **Reviewer role** | Adversarial / misname & ABI attack |
| **Counterpart** | `reviews/A_aa_0052e640_Character_ComputeReverseEngineerSuccessFraction_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Same live Ghidra set as A. **No** `disassemble_bytes`. No Launcher / runtime Confirmed.

---

## 1. Attack surface

Attempted falsifications of Path A claims:

| # | Claim under attack | Attack | Result |
|---:|---|---|---|
| 1 | This VA **is** `UI_ItemHover_ApplyTooltipText` | Partition hint; parent name | **Falsified** — body returns float score; no strings; no widget vtbl+0x308. Parent is dualed `0085ce20`. |
| 2 | Tinkering-skill helper (`Named_CalleeOf_…Tinkering…`) | Prior scaffold from parent plate | **Falsified** — only RE mode-0 / percentage consumers; tinkering strings live in parent modes 4/5, not here. |
| 3 | cdecl / no this | Decompiler `param_1` ambiguity | **Falsified** — `MOV EDI,ECX`; `RET 4`; call sites `MOV ECX,char; PUSH item`. |
| 4 | ECX = item | Parent `FUN_0052e640(in_EAX)` decompile | **Falsified** — parent decompiler drops thiscall ECX; bytes `8B CA` load char into ECX before CALL. |
| 5 | Returns percent already (0–100) | Zero-cost returns 100.0 | **Nuanced** — formula path returns **fraction** (×0.01, cap 0.95); free returns 1.0; zero-cost returns 100.0 which UI `*100` then **clamps to 100**. Consumer always `*100`. Name "Fraction" remains correct for formula path; zero-cost is a clamp-friendly sentinel. |
| 6 | CBID slots are floats / NaN | Decompiler `-NAN` | **Falsified** — asm `CMP EDI,-1`; stores `OR ECX,0xFFFFFFFF`. |
| 7 | Same as required-level `0052e1d0` | Shared callees / layout | **Falsified** — sibling returns **int** required level via `ceil`; this returns **float** fraction; different early free handling (`0052e1d0` returns 0 when free flag set). |
| 8 | Leaf / no stack arg | Ghidra signature `void` | **Falsified** — `RET 4` + stack load of item. |
| 9 | Server authority RNG | UI percentage | **Open** — client math sealed; server not in OWN scope. Does **not** block accept-with-gaps. |
| 10 | Always ≤1.0 | Returns 100.0 | **True nuance** — documented; UI clamp absorbs. Not a reject. |

---

## 2. ABI re-check (hostile)

```text
Entry 0052e640:
  81 EC A8 00 00 00     sub esp, 0xA8
  53                    push ebx
  56                    push esi
  8B B4 24 B4 00 00 00  mov esi, [esp+0xB4]   ; item
  57                    push edi
  33 DB                 xor ebx, ebx
  3B F3                 cmp esi, ebx
  8B F9                 mov edi, ecx          ; character

Exit (all observed):
  C2 04 00              ret 4
```

Call site `0085ce6c` (parent dualed):

```text
56          push esi        ; item
8B CA       mov ecx, edx    ; character
E8 …        call 0052e640
D9 5C 24 10 fstp dword […]
```

**ABI claim stands.**

---

## 3. Semantic re-check

| Path | Return | Consumer effect |
|---|---|---|
| Gate fail / ineligible / over budget | 0.0 | RE tooltip "Requires At Least…" |
| Free flag `+0x6b4≥1` | 1.0 | 100% after ×100 |
| Primary cost 0 | 100.0 | ×100 → clamp 100 → 100% |
| Formula | ≤0.95 | ×100 → ≤95% typical |
| Mid secondary over-cap | 0.0 | fail |

Material type **0x1a** matches dualed parent string path for crafting materials. Skill scale **3.5** shared with `FUN_00520520` cases 0/1.

---

## 4. Naming hostility

| Candidate | Why rejected / kept |
|---|---|
| `UI_ItemHover_ApplyTooltipText` | Parent role; no UI writes here |
| `Named_CalleeOf_…Tinkering…` | Wrong mode domain |
| `Character_ComputeReverseEngineerSuccessPercent` | Formula returns fraction not percent |
| `Item_GetREChance` | Loses character this / skill byte |
| **`Character_ComputeReverseEngineerSuccessFraction_Inferred`** | **Kept** — role + ABI + consumer; `_Inferred` for no PDB |

---

## 5. Residual risks (do not overclaim)

1. Decompiler secondary-loop `unaff_EBX` / `unaff_retaddr` noise — CF sealed via asm structure, not every decompiler temporary.
2. Exact per-tier `need` vector packing in score loop (local_90 layout) — bases/weights/cap sealed; per-slot need wiring **Probable**.
3. Orphan xref `0085d7df` unclaimed — does not change body semantics.
4. No runtime Confirmed.

---

## 6. Verdict

Path A fidelity **stands**. All critical misname / ABI / float-CBID attacks **falsified**. Remaining gaps are product English, sibling duals, orphan site, and runtime — **not** CF/ABI rejects.

**Verdict:** **accept-with-gaps**
