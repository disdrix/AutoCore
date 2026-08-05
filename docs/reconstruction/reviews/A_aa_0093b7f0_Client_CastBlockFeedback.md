# Review A (reconstruction fidelity): `aa_0093b7f0` Client_CastBlockFeedback

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093b7f0` |
| **VA** | `0x0093b7f0` |
| **Canonical name** | `Client_CastBlockFeedback` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0093b7f0_Client_CastBlockFeedback.md` |
| **System tag** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** (strings + CF ladder sealed; vtbl predicate product names open) |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0093b7f0_FUN_0093b7f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0093b7f0_FUN_0093b7f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0093b7f0.cpp` |
| Callers | `Client_CastSkillFromQuickBarSlot` @ `0x009418e0` (`0x00941927`); `FUN_00941ac0` @ `0x00941ac5` |
| Status name table | `FUN_00580a20` @ `0x00580a20` |
| Chat toast | `FUN_008f8200` channel `0x18` |
| Localizer/string pool | `FUN_007a6de0` / `FUN_007a69d0` |

**Live re-decompile + string `search_strings` + `read_memory` + string xrefs performed 2026-07-29.**

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Client/this in EAX; no stack formals | **High** | decomp `in_EAX`; callers call with no args |
| `+0xe98` null → return **1** (silent block) | **High** | CF match both callers treat nonzero as abort |
| Return **1** = blocked (toast path); **0** = allow cast | **Confirmed** | `CastSkillFromQuickBarSlot`: `if (cVar2 != 0) return`; `FUN_00941ac0`: only casts when `== 0` |
| Prefix string sealed | **Confirmed** | `0x00a2e098` → `You can't do that while you are ` |
| Suffix **"dead."** sealed | **Confirmed** | `0x00a2e078`; sole DATA xref `0x0093b892` in this fn |
| Suffix **"waiting."** sealed | **Confirmed** | `0x00a2e06c`; sole DATA xref `0x0093b8e3` in this fn |
| Suffix **"in town."** sealed | **Confirmed** | `0x00a2e060`; sole DATA xref `0x0093b934` in this fn |
| Enhanced-state suffix sealed | **Confirmed** | `0x00a2e080` → `in your enhanced state.` |
| Append `"!"` via `DAT_00a156cc` | **Confirmed** | `read_memory` `0x00a156cc` = `21 00 00 00` (word `'!'`) |
| Toast channel `0x18` when `DAT_00d1b8dc != 0` | **High** | call plate to `FUN_008f8200` |
| Priority: enhanced → dead → waiting → town → flags | **High CF** | nested if ladder order |
| Flag byte dual-base `+0xb8` bits → status names | **High** | `&8`→`FUN_00580a20(2)` "Stunned"; `&0x80`→`"Confused"`; `&0x40`→`"Afraid"` |
| No-match fallthrough returns **0** (not blocked) | **High** | all three flag bits clear after town fail |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null `+0xe98` early return 1 | **Yes** |
| Build prefix into `local_100[256]` | **Yes** |
| Enhanced (`char+0x6b9`) | **Yes** |
| Dead vtbl `+0x198` | **Yes** |
| Waiting vtbl `+0x194` | **Yes** |
| Town flag `*(*(dual+0xa8)+0xf5)` | **Yes** |
| Status bits 8 / 0x80 / 0x40 | **Yes** |
| strcat suffix + `!` + toast | **Yes** |
| return 1 on block; 0 on no block | **Yes** |

---

## 4. Sealed string plate (dead / waiting / town)

| Literal | VA | Bytes (`read_memory`) | Sole code xref |
|---|---|---|---|
| `in town.` | `0x00a2e060` | `69 6e 20 74 6f 77 6e 2e 00` | `0x0093b934` DATA |
| `waiting.` | `0x00a2e06c` | `77 61 69 74 69 6e 67 2e 00` | `0x0093b8e3` DATA |
| `dead.` | `0x00a2e078` | `64 65 61 64 2e 00` | `0x0093b892` DATA |

Contiguous pool packing (also adjacent sealed):

| Literal | VA |
|---|---|
| `in your enhanced state.` | `0x00a2e080` |
| `You can't do that while you are ` | `0x00a2e098` |

Full message shape: **prefix + suffix + `"!"`** e.g. `You can't do that while you are dead.!` wait — decomp appends `DAT_00a156cc` (`!`) after suffix which already ends in `.`, so UX is `…dead.!` **or** localizer may strip; raw CF appends both. **Sealed as written:** suffix includes period; then word `!` is written.

Actually: suffix is `"dead."` and then `*puVar8 = DAT_00a156cc` writes `"!"` at end → **`You can't do that while you are dead.!`**. Confirmed CF.

---

## 5. State ladder (priority first-match)

```
if *(client+0xe98) == 0 → return 1  // silent block
prefix = "You can't do that while you are "
char = *(client+0xe98)
if *(char+0x6b9) != 0 → suffix "in your enhanced state."
else if vtbl[+0x198]() → "dead."
else if vtbl[+0x194]() → "waiting."
else if *( *(entity_dual + 0xa8) + 0xf5 ) → "in town."
else if flags_byte(+0xb8) & 0x08 → name FUN_00580a20(2)  // "Stunned"
else if flags_byte & 0x80 → FUN_00580a20(0x80)          // "Confused"
else if flags_byte & 0x40 → FUN_00580a20(0x40)          // "Afraid"
else → return 0  // allow cast
// strcat suffix; append "!"; toast ch 0x18; return 1
```

Entity dual-base expression (Ghidra):  
`*(int*)(*(int*)(char+4)+4) + 4 + char` for vtbl/`+0xb8`; town uses nested `*(dual + 0xa8)` then `+0xf5`.

---

## 6. Gaps

1. Product English for vtbl `+0x198` / `+0x194` (dead/waiting inferred from **strings** only; method bodies not owned here).
2. Exact product meaning of `char+0x6b9` ("enhanced state") beyond string.
3. Why flag bit `8` maps to status name id `2` (Stunned) not id `8` (Silenced) — sealed mapping; product reason open.
4. Runtime/diff verification open.
5. Whether `FUN_007a6de0` rewrites punctuation (period/`!`) for display.

**Verdict:** **accept-with-gaps** — cast-block feedback helper CF + dead/waiting/town strings **sealed**. Safe hop for cast-gate UX.
