# Review B (adversarial): `aa_0052e1d0` Character_ComputeReverseEngineerRequiredLevel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052e1d0` |
| **VA** | `0x0052e1d0`–`0x0052e636` |
| **Canonical name** | `Character_ComputeReverseEngineerRequiredLevel_Inferred` |
| **Review date** | `2026-08-05` (R11-002 OWN dual) |
| **Reviewer role** | Adversarial / misname & ABI attack |
| **Counterpart** | `reviews/A_aa_0052e1d0_Character_ComputeReverseEngineerRequiredLevel_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Same live Ghidra set as A. **No** `disassemble_bytes`. No Launcher / runtime Confirmed.

---

## 1. Attack surface

Attempted falsifications of Path A claims:

| # | Claim under attack | Attack | Result |
|---:|---|---|---|
| 1 | This VA **is** the ItemHover tooltip | Parent plate / partition parent | **Falsified** — body returns int level; no strings; no widget vtbl+0x308. Parent is dualed `0085ce20`. |
| 2 | Tinkering-skill helper (`Named_CalleeOf_…Tinkering…`) | Prior scaffold from parent plate | **Falsified** — only RE mode-0 consumer; tinkering strings live in parent modes 4/5. |
| 3 | cdecl / no this | Ghidra `undefined FUN_0052e1d0(void)` | **Falsified** — `MOV EDI,ECX`; `RET 4`; item from stack. |
| 4 | ECX = item | Parent decompile `FUN_0052e1d0(in_EAX)` | **Falsified** — parent drops thiscall ECX; prologue binds ECX→character, ESI←item. |
| 5 | Same as twin `0052e640` | Shared callees / layout | **Falsified** — twin returns **float** fraction (ST0); this returns **int** level (EAX); free flag opposite (twin 1.0 / this 0). |
| 6 | Returns success percent | Shared RE domain | **Falsified** — consumer uses `%d` level string, not `%.01f%%`. |
| 7 | Leaf / no stack arg | Ghidra signature void | **Falsified** — `RET 4` + stack load of item. |
| 8 | ST0 float return | FPU `ceil` use | **Falsified** — ceil feeds integer local_34; exits via EAX; call site no FSTP. |
| 9 | Scale 3.5 not 1/3.5 | Twin skill budget | **Falsified** — `read_memory` `009cdff4` = 0.2857143 = 1/3.5; formula is `ceil(cost * inv)`. |
| 10 | Server authority | UI string only | **Open** — client math sealed; does not block accept-with-gaps. |

---

## 2. ABI re-check (hostile)

```text
Entry 0052e1d0:
  83 EC 38              sub esp, 0x38
  53 56                 push ebx / esi
  8B 74 24 44           mov esi, [esp+0x44]   ; item
  57                    push edi
  33 DB                 xor ebx, ebx
  3B F3                 cmp esi, ebx
  8B F9                 mov edi, ecx          ; character
  8B 86 A8 00 00 00     mov eax, [esi+0xa8]

Exit (observed):
  83 C4 38              add esp, 0x38
  C2 04 00              ret 4                 ; @ 0052e629 and 0052e634
```

Call site `0085cfe9` (parent dualed): `CALL 0052e1d0` then value used as `sprintf` `%d` arg (not FSTP).

**ABI claim stands.**

---

## 3. Semantic re-check

| Path | Return | Consumer effect |
|---|---|---|
| Null item / no slots | 0 | (parent usually already gated) |
| Free flag `+0x6b4>0` | 0 | twin shows success; no "Requires At Least" |
| primary cost 0 | 0 | no level string from this path |
| Normal | max(ceil(primary/3.5), tier maps) | `"Requires At Least N Reverse Engineering"` |

Material type **0x1a** matches twin / parent crafting-material gate. Inv mults match dualed `Character_GetReverseEngineerSkillCapacityByTier_Inferred` capacity table inverted.

---

## 4. Naming hostility

| Candidate | Why rejected / kept |
|---|---|
| `Named_CalleeOf_…Tinkering…` | Wrong domain strings |
| `Character_ComputeReverseEngineerSuccessFraction` | Twin only; wrong return type |
| `Item_GetRequiredLevel` | Too generic; RE-specific formula |
| `UI_ItemHover_…` | Parent role |
| **`Character_ComputeReverseEngineerRequiredLevel_Inferred`** | **Kept** — role + ABI + consumer `%d`; `_Inferred` for no PDB |

---

## 5. Residual risk

- `FUN_005206d0` not dualled in this OWN pass (CF sealed via decompile + float table).
- Secondary-loop register noise may hide a micro-ordering difference vs image FPU CW restore.
- No runtime / differential.

**Does not block accept-with-gaps.**

---

## 6. Verdict

Path A stands under adversarial attack. **accept-with-gaps**.
