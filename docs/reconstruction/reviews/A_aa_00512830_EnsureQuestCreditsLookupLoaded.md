# Review A (reconstruction fidelity): `aa_00512830` EnsureQuestCreditsLookupLoaded

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512830` |
| **VA** | `0x00512830` |
| **Canonical name** | `EnsureQuestCreditsLookupLoaded` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_00512830_EnsureQuestCreditsLookupLoaded.md` |
| **System** | `missions-progression` |
| **Tools** | Ghidra `decompile_function`, `read_memory`, `get_function_*`, `list_globals`, `get_xrefs_to` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin **ensure-load wrapper** that brings the retail `tQuestCreditsLookup` table into the client global map used by `Mission_ComputeObjectiveCredits`. Body always runs the DB/WAD bookend pair + `LoadQuestCreditsLookupFromWad`; it does **not** early-out on a ready flag (that gate lives in callers). On negative load status it emits `VOG_DEBUG_STOP` via `FUN_007a4480(0, "VOG_DEBUG_STOP")`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00512830_EnsureQuestCreditsLookupLoaded.md` |
| Annotated | `docs/reconstruction/raw/aa_00512830_EnsureQuestCreditsLookupLoaded.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EnsureQuestCreditsLookupLoaded.cpp` |
| Function record | `docs/reconstruction/functions/aa_00512830_EnsureQuestCreditsLookupLoaded.md` |
| Loader dual | `reviews/A_aa_007cc470_LoadQuestCreditsLookupFromWad.md` |
| Primary consumer | `functions/aa_0059df20_Mission_ComputeObjectiveCredits.md` |
| Sibling ensure | `0x00512870` `EnsureQuestBaseCreditsLoaded` (byte-identical shape) |

---

## 3. Assembly-sealed body (`read_memory` @ `0x00512830`, 62 bytes → `ret`)

```text
00512830  8B0D9C46B000      mov  ecx, dword ptr [0x00b0469c]   ; g_pDbReaderCtx*
00512836  56                push esi
00512837  E844F52C00        call FUN_007e1d80                   ; enter / refcount++
0051283C  8B0D9C46B000      mov  ecx, dword ptr [0x00b0469c]
00512842  685842B000        push 0x00b04258                     ; &g_pQuestCreditsLookupMap
00512847  E8249C2B00        call LoadQuestCreditsLookupFromWad  ; 0x007cc470
0051284C  8B0D9C46B000      mov  ecx, dword ptr [0x00b0469c]
00512852  8BF0              mov  esi, eax                       ; load status
00512854  E897552A00        call FUN_007b7df0                   ; leave / refcount--
00512859  85F6              test esi, esi
0051285B  5E                pop  esi
0051285C  7D0F              jge  0051286d                       ; status >= 0 → ret
0051285E  684458A100        push 0x00a15844                     ; "VOG_DEBUG_STOP"
00512863  6A00              push 0
00512865  E8161C2900        call FUN_007a4480
0051286A  83C408            add  esp, 8
0051286D  C3                ret
```

Body range (Ghidra): `00512830`–`0051286d`. Sibling `EnsureQuestBaseCreditsLoaded` starts at `00512870`.

String at `0x00a15844` (`read_memory`): ASCII `VOG_DEBUG_STOP\0`.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| No args, void return (`ret` only) | **High** | No stack args; EAX not consumed by callers for return value |
| Always calls Load (no in-body ready gate) | **High** | Linear flow; plate “if already loaded: return” is **false for this body** |
| ECX = `*[0x00b0469c]` for enter / load / leave | **High** | Three identical `mov ecx,[0x00b0469c]` |
| Stack arg to Load = `0x00b04258` map root | **High** | Imm push; global named `g_pQuestCreditsLookupMap_Inferred` |
| Load VA `0x007cc470` | **High** | Rel32 decodes to named callee |
| Fail path: `FUN_007a4480(0,"VOG_DEBUG_STOP")` if status `< 0` | **High** | `test/jge` + cdecl push order + `add esp,8` |
| Contiguous globals block | **High** | `list_globals`: map `00b04258`, end `00b0425c`, loaded `00b04260` |
| Callers: `Mission_ComputeObjectiveCredits`, `FUN_0094a6a0` | **High** | `get_function_callers` + xrefs `0059df91`, `0059dfb5`, `0094afb8` |
| Ready-flag write in this unit | **N/A / none** | Body never touches `00b04260` |
| `FUN_007e1d80` / `FUN_007b7df0` product names | **Medium** | Behavior = DB connection enter/leave (refcount @ `ctx+0x20`); names still FUN_* |
| Decompiler `Load(&map)` as sole arg | **Low as literal** | Asm is **ECX=ctx + push map**; clean/raw under-describe ECX |

---

## 5. Control flow: clean ≡ raw ≡ asm

| Stage | Match |
|---|---|
| enter → Load → leave → optional VOG_DEBUG_STOP | **Yes** |
| Early return if loaded | **No** (not present; plate overstated) |
| Sets `g_nQuestCreditsLookupLoaded_Inferred` | **No** in this body |

---

## 6. Call graph (this unit)

**Callees**

| VA | Name | Role |
|---|---|---|
| `0x007e1d80` | `FUN_007e1d80` | DB/RM enter; `ctx+0x20++`; may open connection when `DAT_00d1793c==0` |
| `0x007cc470` | `LoadQuestCreditsLookupFromWad` | Parse `//tQuestCreditsLookup/row` (xpath sealed on loader) |
| `0x007b7df0` | `FUN_007b7df0` | DB leave; `ctx+0x20--`; release COM when 0 |
| `0x007a4480` | `FUN_007a4480` | Debug / assert log |

**Callers**

| Site | Function | Gate |
|---|---|---|
| `0x0059df91`, `0x0059dfb5` | `Mission_ComputeObjectiveCredits` | `cmp [0x00b04260],0` then conditional call (lazy path) |
| `0x0094afb8` | `FUN_0094a6a0` | Boot / clonebase table bring-up (with BaseCredits + XP ensures); no flag gate |

---

## 7. Gaps / open

1. Static write site for `g_nQuestCreditsLookupLoaded_Inferred` (`0x00b04260`) — only **READ** xrefs from `Mission_ComputeObjectiveCredits` (likely written via pointer math inside Load; not sealed here).
2. Whether `LoadQuestCreditsLookupFromWad` is idempotent if Ensure is re-entered with flag still 0.
3. Product names for enter/leave helpers and `DAT_00b0469c` object type.
4. Full COM/DB vs WAD branch of Load (owned by `aa_007cc470`).
5. Runtime / bit-exact image diff not run.

**Verdict:** **accept-with-gaps**
