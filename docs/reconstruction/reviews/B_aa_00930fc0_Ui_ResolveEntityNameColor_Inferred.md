# Review B (skeptical / adversarial): `aa_00930fc0` Ui_ResolveEntityNameColor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00930fc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00930fc0_Ui_ResolveEntityNameColor_Inferred.md` |
| **Verdict** | **accept-with-gaps** on role/ABI/CF; product name residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is a skill cast / RequestCast residual | Callers are UI draw (`00836410` name sprintf + color + text); no cast opcodes | **Falsified as cast manager** |
| 2 | `cdecl` / 0 stack cleanup | `ret 16` | **Falsified** |
| 3 | Returns color in EAX only | Body stores `*param_3`; decompiler void | **Out-param sealed**; EAX unused for color |
| 4 | Purple means faction ally | Only gate is `sub+0x6b4 > 0` after `vtbl+0x210` | **English open**; CF sealed as “marked counter” |
| 5 | `0xDFCAFF0B` is full-opaque green | Alpha byte `0xDF` ≠ `0xFF` | **Survives** — semi-opaque lime |
| 6 | Crew check uses entity root as member | Passes `vtbl+0x210` sub + local `+0xcb0` host | **Survives** as VehicleCrew path (dualed `005749d0`) |
| 7 | Same unit as `FUN_00930f40` | Different VA; palette is callee | **Falsified** |
| 8 | Always computes level color | Many early exits to palette; level path needs identity + flags | **Falsified as always** |
| 9 | Product name sealed without string/RTTI | No demangle | **`_Inferred` required** |
| 10 | `param_1` is clientCtx (thiscall swapped) | ECX storage entity; ctx at stack+4; UI callers load entity into ECX | **Entity-in-ECX sealed** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Out ARGB store + ret 16 | **High** | Wrong UI ABI |
| Special color immediates | **High** | Wrong nameplate look |
| Not cast pipeline | **High** | Mis-file under skills cast |
| Purple field English | **Open** | Doc only |
| Product symbol | **Open** | Doc only |
| Runtime | **Open** | Unverified live |

---

## 3. Surviving contract

```
Ui_ResolveEntityNameColor(entity, clientCtx, &outArgb, flagA, flagB)
  // writes outArgb; does not return color in EAX
  // local player = *(clientCtx+0xe98)
  // specials: purple / gray / lime / level-band / else palette FUN_00930f40
```

Parents feed entity + draw name strings; color is for text/nameplate only.

---

## 4. Residual uncertainty

| # | Item | Blocks rename seal? |
|---|---|---|
| R1 | Product name | No (`_Inferred`) |
| R2 | `+0x6b4` English | No |
| R3 | flagA/flagB product names | No |
| R4 | `FUN_0092d580` dual | No for this unit CF |
| R5 | Runtime / bit-exact | No |

**Verdict:** **accept-with-gaps**.
