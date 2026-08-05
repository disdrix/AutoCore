# Review A (reconstruction fidelity): `aa_00512870` EnsureQuestBaseCreditsLoaded

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512870` |
| **VA** | `0x00512870` |
| **Canonical name** | `EnsureQuestBaseCreditsLoaded` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_00512870_EnsureQuestBaseCreditsLoaded.md` |
| **System** | `missions-progression` |
| **Tools** | Ghidra `decompile_function`, `read_memory`, `get_function_*`, `list_globals`, `get_xrefs_to`, `audit_globals_in_function` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin **ensure-load wrapper** that brings the retail `tQuestBaseCredits` table into the client global map used by `Mission_ComputeObjectiveCredits` (base credits term keyed by target level). Body always runs the DB/WAD bookend pair + `LoadQuestBaseCreditsFromWad`; it does **not** early-out on a ready flag (that gate lives in callers). On negative load status it emits `VOG_DEBUG_STOP` via `FUN_007a4480(0, "VOG_DEBUG_STOP")`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00512870_EnsureQuestBaseCreditsLoaded.md` |
| Annotated | `docs/reconstruction/raw/aa_00512870_EnsureQuestBaseCreditsLoaded.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EnsureQuestBaseCreditsLoaded.cpp` |
| Function record | `docs/reconstruction/functions/aa_00512870_EnsureQuestBaseCreditsLoaded.md` |
| Loader | `LoadQuestBaseCreditsFromWad` @ `0x007cc810` (xpath `//tQuestBaseCredits/row` on plate) |
| Primary consumer | `functions/aa_0059df20_Mission_ComputeObjectiveCredits.md` |
| Sibling ensure | `0x00512830` `EnsureQuestCreditsLookupLoaded` (byte-identical shape; dual sealed) |

---

## 3. Assembly-sealed body (`read_memory` @ `0x00512870`, 62 bytes → `ret`)

```text
00512870  8B0D9C46B000      mov  ecx, dword ptr [0x00b0469c]   ; g_pDbReaderCtx*
00512876  56                push esi
00512877  E804F52C00        call FUN_007e1d80                   ; enter / refcount++
0051287C  8B0D9C46B000      mov  ecx, dword ptr [0x00b0469c]
00512882  686442B000        push 0x00b04264                     ; &g_pQuestBaseCreditsMap
00512887  E8849F2B00        call LoadQuestBaseCreditsFromWad    ; 0x007cc810
0051288C  8B0D9C46B000      mov  ecx, dword ptr [0x00b0469c]
00512892  8BF0              mov  esi, eax                       ; load status
00512894  E857552A00        call FUN_007b7df0                   ; leave / refcount--
00512899  85F6              test esi, esi
0051289B  5E                pop  esi
0051289C  7D0F              jge  005128ad                       ; status >= 0 → ret
0051289E  684458A100        push 0x00a15844                     ; "VOG_DEBUG_STOP"
005128A3  6A00              push 0
005128A5  E8D61B2900        call FUN_007a4480
005128AA  83C408            add  esp, 8
005128AD  C3                ret
```

Body range (Ghidra): `00512870`–`005128ad`. Immediately follows sibling `EnsureQuestCreditsLookupLoaded` (`00512830`–`0051286d`).

String at `0x00a15844` (`read_memory`): ASCII `VOG_DEBUG_STOP\0`.

Rel32 seals:

| Call site | rel32 | Target |
|---|---|---|
| `00512877` | `+0x002cf504` | `FUN_007e1d80` |
| `00512887` | `+0x002b9f84` | `LoadQuestBaseCreditsFromWad` `0x007cc810` |
| `00512894` | `+0x002a5557` | `FUN_007b7df0` |
| `005128a5` | `+0x00291bd6` | `FUN_007a4480` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| No args, void return (`ret` only) | **High** | No stack args; EAX not consumed by callers for return value |
| Always calls Load (no in-body ready gate) | **High** | Linear flow; plate “if already loaded: return” is **false for this body** |
| ECX = `*[0x00b0469c]` for enter / load / leave | **High** | Three identical `mov ecx,[0x00b0469c]` |
| Stack arg to Load = `0x00b04264` map root | **High** | Imm push; global named `g_pQuestBaseCreditsMap_Inferred` |
| Load VA `0x007cc810` | **High** | Rel32 decodes to named callee; plate xpath `//tQuestBaseCredits/row` |
| Fail path: `FUN_007a4480(0,"VOG_DEBUG_STOP")` if status `< 0` | **High** | `test/jge` + cdecl push order + `add esp,8` |
| Contiguous globals block | **High** | `list_globals`: map `00b04264`, end `00b04268`, loaded `00b0426c` |
| Callers: `Mission_ComputeObjectiveCredits`, `FUN_0094a6a0` | **High** | `get_function_callers` + xrefs `0059df41`, `0059df65`, `0094afbd` |
| Ready-flag write in this unit | **N/A / none** | Body never touches `00b0426c` |
| Sibling isomorphism with `0x00512830` | **High** | Same 62-byte skeleton; only map imm + Load rel32 differ |
| `FUN_007e1d80` / `FUN_007b7df0` product names | **Medium** | Behavior = DB connection enter/leave (refcount @ `ctx+0x20`); names still FUN_* |
| Decompiler `Load(&map)` as sole arg | **Low as literal** | Asm is **ECX=ctx + push map**; clean/raw v1 under-describe ECX (fixed in clean v2) |

---

## 5. Control flow: clean ≡ raw ≡ asm

| Stage | Match |
|---|---|
| enter → Load → leave → optional VOG_DEBUG_STOP | **Yes** |
| Early return if loaded | **No** (not present; plate overstated) |
| Sets `g_nQuestBaseCreditsLoaded_Inferred` | **No** in this body |

Clean (post dual) documents ECX plumbing explicitly; raw v1 plate still carries the misleading early-out text (v2 append corrects).

---

## 6. Call graph (this unit)

**Callees**

| VA | Name | Role |
|---|---|---|
| `0x007e1d80` | `FUN_007e1d80` | DB/RM enter; `ctx+0x20++`; may open connection when `DAT_00d1793c==0` |
| `0x007cc810` | `LoadQuestBaseCreditsFromWad` | Parse `//tQuestBaseCredits/row` (xpath sealed on loader plate) |
| `0x007b7df0` | `FUN_007b7df0` | DB leave; `ctx+0x20--`; release COM when 0 |
| `0x007a4480` | `FUN_007a4480` | Debug / assert log |

**Callers**

| Site | Function | Gate |
|---|---|---|
| `0x0059df41`, `0x0059df65` | `Mission_ComputeObjectiveCredits` | `cmp [0x00b0426c],0` then conditional call (lazy path) |
| `0x0094afbd` | `FUN_0094a6a0` | Boot / clonebase table bring-up (with CreditsLookup + XP ensures); no flag gate |

---

## 7. Sibling delta (`0x00512830`)

| Field | BaseCredits (`0x00512870`) | CreditsLookup (`0x00512830`) |
|---|---|---|
| Map root imm | `0x00b04264` | `0x00b04258` |
| Loaded flag | `0x00b0426c` | `0x00b04260` |
| Load callee | `0x007cc810` | `0x007cc470` |
| Table / xpath | `tQuestBaseCredits` / `//tQuestBaseCredits/row` | `tQuestCreditsLookup` / `//tQuestCreditsLookup/row` |
| Body size / skeleton | 62 bytes | 62 bytes (byte-isomorphic) |

---

## 8. Gaps / open

1. Static write site for `g_nQuestBaseCreditsLoaded_Inferred` (`0x00b0426c`) — only **READ** xrefs from `Mission_ComputeObjectiveCredits` (likely written via pointer math inside Load; not sealed here).
2. Whether `LoadQuestBaseCreditsFromWad` is idempotent if Ensure is re-entered with flag still 0.
3. Product names for enter/leave helpers and `DAT_00b0469c` object type.
4. Full COM/DB vs WAD branch of Load (owned by `aa_007cc810` / loader dual).
5. Runtime / bit-exact image diff not run.

**Verdict:** **accept-with-gaps**
