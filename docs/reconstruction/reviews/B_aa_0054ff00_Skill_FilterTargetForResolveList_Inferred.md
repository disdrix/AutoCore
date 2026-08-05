# Review B (skeptical / adversarial): `aa_0054ff00` Skill_FilterTargetForResolveList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054ff00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0054ff00_Skill_FilterTargetForResolveList_Inferred.md` |
| **Verdict** | **accept** on outFlags writers (machine sites); **accept-with-gaps** on vtbl product names / 0x10 UX / flag English |
| **Residual scratch** | `tmp/a_0054ff00.md` |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Also writes outFlags bits 1 and 2 | **Falsified** — only 4, 8, 0x10; three `OR [EAX], imm` sites only (`read_memory` + pcode INT_OR = 3) |
| 2 | GatherTargetsInArea writes bit 4/8 | **Falsified for 4/8/0x10** — exclusive filter writer; ResolveTargetList only ORs 1/2 |
| 3 | Name is product-original | **Holds as false** — `_Inferred` required |
| 4 | null candidate always rejects with bit4 | **Mostly holds** — null path may redirect to self/owner under `+0x614&1` + mode 0/1/0xb; owner-miss returns null **without** OR |
| 5 | Bit8 = “hostile” exclusively | **Overstated** — gate is `vtbl+0x198` non-zero while Remains (`+0x615&4`) clear; pairs with Remains tooltip → **remains/dead-like**, not pure faction-hostile |
| 6 | Decompile OR sites could be wrong / optimized away | **Falsified** — exact bytes at `0x0054ff72` / `0x0055007c` / `0x005502c1` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bits 4/8/0x10 writers here (exact VA) | **Confirmed** | Wrong cast fail UX mapping |
| Sole caller | **Confirmed** | Miss other writers |
| Exclusive chain writer for 4/8/0x10 | **Confirmed** | Mis-attribute Gather/range |
| Bit8 English (“hostile” vs remains) | **High behavior / Probable English** | Wrong fail-code narrative |
| Type set `{0xe,0x12,0x14}` product names | Partial | Wrong object-class filter |
| Full targeting matrix | Partial | Incorrect multi-target allow |
| Bit 0x10 UX | Open | Silent reject |

---

## 3. Surviving contract

```
FilterTargetForResolve(skill, candidate, caster, &outFlags) -> object*|null
  reject sites (machine):
    0x0054ff72: outFlags |= 8    ; remains/dead-like when Remains flag clear
    0x0055007c: outFlags |= 0x10 ; type not in {0xe,0x12,0x14}
    0x005502c1: outFlags |= 4    ; LAB_005502bd fallthrough + early gotos
  on accept: return object* (no outFlags OR)
  ABI: __thiscall, 3 stack args, RET 0x0C
ResolveTargetList still owns bits 1 (no target) and 2 (range).
```

---

## 4. Residual uncertainty

| # | Item | Blocks writer seal? |
|---|---|---|
| R1 | `vtbl+0x198` / `+0x1d4` / `+0x298` product names | No |
| R2 | Every skill flag bit English | No (tooltip High for used bits) |
| R3 | Bit 0x10 UX | No |
| R4 | Original C++ name | No (`_Inferred`) |
| R5 | Runtime e2e / bit-exact | No (matrix policy) |

---

## 5. Concrete checks (residual pass)

1. Re-decompile `0x0054ff00` — CF ≡ raw/clean.
2. `read_memory`: `83 08 08` @ `0x0054ff72`, `83 08 10` @ `0x0055007c`, `83 08 04` @ `0x005502c1`.
3. Callers list = only ResolveTargetList.
4. ResolveTargetList body only `|=1` / `|=2`.
5. ResolveCastTarget branches on bits 1/2/4/8 after list build; bit 0x10 not special-cased.

---

## 6. Verdict

**accept** — outFlags bit **4**, **8**, and **0x10** writers **machine-closed** at this function with exclusive chain ownership. Name remains `_Inferred`. Gaps on vtbl product English and 0x10 UX do **not** reopen the writer seal.
