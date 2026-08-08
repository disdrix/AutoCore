# Independent adversarial spot-check — WQ9E-C + WQ9E-E (`ui` + `erase`)

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** dual author for WQ9E-C or WQ9E-E) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | WQ-009 depth-2 residual dual seal — **WQ9E-C** (name-color helpers) + **WQ9E-E** (isnil29 erase/insert) |
| **Units** | (1) `0x00930f40` `Ui_NameColorPalette_WriteArgb_Inferred` + `0x0092d580` `Ui_NameColorLevelBand_CopyFloat4_Inferred` (WQ9E-C) |
| | (2) `0x004cb740` `StdTree_EraseAndRebalance_Isnil29_Inferred` + `0x004cbb60` `StdTree_InsertAndRebalance_Isnil29_Inferred` (WQ9E-E) |
| **Tools** | Dual reports + A/B + raw/annotated/clean + function records; Ghidra batch-capture cross-check (`tmp_batch_waveE_599` / `596` / `047`); dual-appended `read_memory` hex; **no** `disassemble_bytes` |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** (no runtime Confirmed) |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-00930f40-0092d580-wq9ec-report.md` |
| `docs/agents/task-dual-ab-004cb740-004cbb60-wq9ee-report.md` |
| `docs/reconstruction/reviews/A_aa_00930f40_Ui_NameColorPalette_WriteArgb_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00930f40_Ui_NameColorPalette_WriteArgb_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0092d580_Ui_NameColorLevelBand_CopyFloat4_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0092d580_Ui_NameColorLevelBand_CopyFloat4_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_004cb740_StdTree_EraseAndRebalance_Isnil29_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_004cb740_StdTree_EraseAndRebalance_Isnil29_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_004cbb60_StdTree_InsertAndRebalance_Isnil29_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_004cbb60_StdTree_InsertAndRebalance_Isnil29_Inferred.md` |

### Artifacts (four VAs)

| Kind | `aa_00930f40` | `aa_0092d580` | `aa_004cb740` | `aa_004cbb60` |
|---|---|---|---|---|
| Raw (+ re-verify) | `raw/aa_00930f40_FUN_00930f40.md` | `raw/aa_0092d580_FUN_0092d580.md` | `raw/aa_004cb740_FUN_004cb740.md` | `raw/aa_004cbb60_FUN_004cbb60.md` |
| Annotated | `…FUN_00930f40.annotated.md` | `…FUN_0092d580.annotated.md` | `…FUN_004cb740.annotated.md` | `…FUN_004cbb60.annotated.md` |
| Clean named (claimed) | `Ui_NameColorPalette_WriteArgb_Inferred.cpp` | `Ui_NameColorLevelBand_CopyFloat4_Inferred.cpp` | `StdTree_EraseAndRebalance_Isnil29_Inferred.cpp` | `StdTree_InsertAndRebalance_Isnil29_Inferred.cpp` ⚠️ |
| Clean twin / scaffold | `FUN_00930f40.cpp` | `FUN_0092d580.cpp` | `FUN_004cb740.cpp` | `FUN_004cbb60.cpp` |
| Function named | `aa_00930f40_Ui_…` | `aa_0092d580_Ui_…` | `aa_004cb740_StdTree_…` | `aa_004cbb60_StdTree_…` |

⚠️ = **material artifact finding** (see Unit D): claimed clean plate currently documents a **different VA** (`0x00406c40` / WQ9E-G).

### Independent CF cross-checks

| Check | Result |
|---|---|
| Batch decompile `0x00930f40` (`tmp_batch_waveE_599`) | switch modes 0 / default / 2 / 3 / `0xffffffff`; BGRA stores match dual palette |
| Batch decompile `0x0092d580` (`tmp_batch_waveE_596`) | signed ladder + 4×dword copy; offsets `0xbe4`…`0xc54` match dual band map |
| Batch decompile `0x004cb740` + `0x004cbb60` (`tmp_batch_waveE_047`) | erase isnil@+0x29 throw + RB + false-noreturn delete; insert max `0xaaaaaa8` + buynode `FUN_005a2de0` + isnil29 rotates |
| Dual raw re-verify hex (WQ9E-C / WQ9E-E 2026-08-04) | palette JT/`C3`; band ladder/`C3`; erase epilogue `…c20800`; insert exit `…c21000` |
| Parent consumer `0x00930fc0` in same bulk | calls palette + band; packs floats × `DAT_00aaa6f8` with A=`0xFF` |
| Peer insert collision | `aa_00406c40_StdTree_InsertAndRebalance_Isnil29_Inferred.md` owns **same clean filename** for `0x00406c40` |

---

## Unit A — `0x00930f40` Ui_NameColorPalette_WriteArgb_Inferred (WQ9E-C)

### Body / ABI / CF seal (independent)

| Claim | Independent result |
|---|---|
| Body `0x00930f40`–`0x00930f9c` exclusive (**92 B**); JT 5×dword @ `0x00930fa0` | **Confirmed** — dual re-verify + JT note; bulk decompile is pure switch leaf |
| **ECX** = signed mode; **EAX** = out `uint8_t[4]`; bare **`C3`** | **Confirmed** — raw byte notes `add ecx,1` / stores to `[eax]`; decomp shows `in_EAX` + `__fastcall(param_1)` only (incomplete formal list is honest) |
| Algorithm `idx = mode+1`; `idx>4` → beige default | **Confirmed** — raw `cmp ecx,4` / `ja default` + JT |
| Palette: 0 red `0xFFC41616`; 1/default beige `0xFFDCE0C8`; 2 cyan `0xFF66D3EA`; 3 green `0xFF14D314`; −1 white `0xFFFFFFFF` | **Confirmed** — bulk decompile channel bytes match clean + dual table |
| Memory order B,G,R,A (BGRA) / dword LE AARRGGBB | **Confirmed** |
| Sole code caller `Ui_ResolveEntityNameColor` (`0x00930fc0`) — **6** sites | **High** — dual sites; bulk parent decompile shows multiple `FUN_00930f40()` uses |
| Live parent modes include 0,1,2,2\|3; white implemented, unused by current xrefs | **High** — dual call-site table; not contested by bulk CF |
| Leaf (no callees) | **Confirmed** |
| Product English / mode labels (hostile/ally…) | **Open** — `_Inferred` hygiene correct |
| Runtime / bit-exact | **Open** — Terminal false honest |

### Live decompile (independent summary)

```c
void __fastcall FUN_00930f40(undefined4 param_1) {
  undefined1 *in_EAX;
  switch(param_1) {
  case 0:   /* B=0x16 G=0x16 R=0xC4 A=0xFF */ break;
  default:  /* B=200 G=0xE0 R=0xDC A=0xFF beige */ break;
  case 2:   /* cyan */ break;
  case 3:   /* green */ break;
  case 0xffffffff: /* white */ break;
  }
}
```

Matches clean named reconstruction and dual A CF table.

### Adversarial attacks (palette)

| # | Attack | Result |
|---|---|---|
| 1 | This is the full name-color resolver | **Fails** — leaf switch/stores only; resolver is `0x00930fc0` |
| 2 | Same unit as level-band `0x0092d580` | **Fails** — different VA/ABI/data |
| 3 | Standard MSVC `__fastcall` (ECX,EDX) formals | **Fails as standard** — out is **EAX**, not EDX |
| 4 | Always red (parent often passes 0) | **Fails** — other sites pass 1,2,2\|3 |
| 5 | Channel order ARGB in memory | **Fails** — B@0 G@1 R@2 A@3 |
| 6 | Mode 1 has distinct non-default case in switch | **Survives as dual stated** — mode1 falls to default beige (JT) |
| 7 | Product/PDB name sealed | **Fails** — `_Inferred` required |
| 8 | Ready for Confirmed runtime | **Fails** — dual gap correctly owned |

### Soft niggles (not sealed-claim failures)

1. Decompiler `void` omits return-as-out; dual/clean document EAX correctly.
2. Mode product English (hostile/neutral/friend) open by design.

### Unit A dual quality

**PASS** — keep **`accept`**.

---

## Unit B — `0x0092d580` Ui_NameColorLevelBand_CopyFloat4_Inferred (WQ9E-C)

### Body / ABI / CF seal (independent)

| Claim | Independent result |
|---|---|
| Body `0x0092d580`–`0x0092d5fb` exclusive (**123 B**); leaf; `CC` after `ret` | **Confirmed** — dual re-verify range |
| **ECX** host; **EDX** signed `levelDiff`; **EAX** out 16 B; bare **`C3`** | **Confirmed** — bulk decompile `param_1`/`param_2` + `in_EAX`; raw `cmp edx,7` ladder |
| Eight bands stride **0x10**: ≤−5 `+0xBE4` … ≥7 `+0xC54` | **Confirmed** — bulk decompile offsets exact match dual table |
| Four dword copy to out | **Confirmed** |
| Parent name path packs RGB × `DAT_00aaa6f8` (255.0f), A=`0xFF` | **Confirmed** — bulk `0x00930fc0` uses `FUN_0092d580` then ×`DAT_00aaa6f8` |
| Callers: name color + mission dialog + journal family | **High** — dual xrefs; multi-caller role name correct |
| Not combat accuracy / skill level-band math | **Confirmed** — UI callers only in dual graph |
| Host RTTI / live float contents | **Open** — dual residual fair |
| Fourth float English (alpha vs pad) | **Open** — dual residual fair |
| Runtime / bit-exact | **Open** — Terminal false |

### Band map re-check (from bulk decompile)

| levelDiff | offset | Bulk |
|---|---|---|
| `< 7` fail → else | `+0xC54` | yes |
| `< 5` fail | `+0xC44` | yes |
| `< 3` fail | `+0xC34` | yes |
| `< 1` fail | `+0xC24` | yes |
| `< -4` | `+0xBE4` | yes |
| `< -2` | `+0xBF4` | yes |
| unsigned `< 0x80000000` (0) | `+0xC14` | yes |
| else (−2..−1) | `+0xC04` | yes |

Clean ladder (`>=7`…`else 0`) is **equivalent** to decompiler nested form.

### Adversarial attacks (level-band)

| # | Attack | Result |
|---|---|---|
| 1 | Combat accuracy / skill band helper | **Fails** — UI name + mission dialog consumers |
| 2 | Returns packed ARGB itself | **Fails** — float4 copy; parent multiplies |
| 3 | Same as palette `0x00930f40` | **Fails** |
| 4 | levelDiff 0 and −1 share a slot | **Fails** — 0→`+0xC14`; −1/−2→`+0xC04` |
| 5 | Scaffold `CalleeOf_NpcDialog` is product role | **Fails** — multi-caller leaf; role name supersedes |
| 6 | Decompiler unsigned `param_2 < 0x80000000` breaks signed ladder | **Fails as material** — maps 0 vs negative correctly |
| 7 | Product host class sealed | **Fails** — open residual |
| 8 | Runtime Confirmed | **Fails** |

### Soft niggles

1. Host formal type unlabeled beyond “table owner.”
2. Float RGB contents require initialized host dump (correctly residual).

### Unit B dual quality

**PASS** — keep **`accept`**.

---

## Unit C — `0x004cb740` StdTree_EraseAndRebalance_Isnil29_Inferred (WQ9E-E)

### Body / ABI / CF seal (independent)

| Claim | Independent result |
|---|---|
| Body exclusive end **`0x004cb9f5`** (**693 B** / `0x2B5`); Ghidra list end `0x004cb9c6` truncated by false noreturn | **Confirmed** — bulk decompile ends at `operator_delete` with noreturn warning; dual epilogue hex ends `c20800` |
| **`__thiscall`**; ECX=map; stack `outIt`, `node`; **RET 8** | **Confirmed** — decomp signature + dual exit hex `C2 08 00` |
| Nil → `"invalid map/set<T> iterator"` / `DAT_00acc34c` | **Confirmed** — bulk decompile |
| isnil@**+0x29**, color@**+0x28** | **Confirmed** — `*(char*)(param_3+0x29)`, `param_3[10]` color |
| Successor prep `FUN_004cb270`; min `FUN_0051b5d0`; max `FUN_00421b50`; L/R `004192a0`/`004192f0` | **Confirmed** — bulk callees |
| Single-node erase (not range/clear) | **Confirmed** — bulk CF; range erase is `FUN_004cbaa0` which **calls** this |
| size-- + `*outIt` after delete (decomp miss) | **High** — dual epilogue hex documents size--/`*outIt`; clean comments byte-sealed epilogue |
| Callers (3): `FUN_004c8610`, `FUN_004c8780`, `FUN_004cbaa0` | **High** — dual xrefs; bulk shows `004cbaa0` → `004cb740` |
| Peer Val12 erase `0x004e4130` (isnil@+0x19) must not merge | **Confirmed** — different isnil offset family |
| Product demangle / map value_type | **Open** — `_Inferred` correct |
| Runtime / bit-exact | **Open** |

### Adversarial attacks (erase)

| # | Attack | Result |
|---|---|---|
| 1 | Decompiler body is complete (ends at delete) | **Fails** — false noreturn; epilogue continues (size-- / outIt / ret 8) |
| 2 | Val12 layout isnil@+0x19 / color@+0x18 | **Fails** — this unit **+0x29 / +0x28** |
| 3 | Same binary as Val12 erase `0x004e4130` | **Fails** — different VA/rotates/isnil |
| 4 | Frees whole tree / range | **Fails** — single-node; range is caller `004cbaa0` |
| 5 | VOG_DEBUG_STOP scaffold name is product role | **Fails** — shared tree helper; three map callers |
| 6 | No size update | **Fails** — epilogue size-- when size>0 |
| 7 | Skill-domain exclusive | **Fails** — structural std tree |
| 8 | Product demangle sealed | **Fails** |

### Soft niggles

1. Clean plate stubs `*outIt` as `(void)outIt` after documenting byte-seal — **docs honesty OK**, but clean is not a full epilogue rewrite. Prefer an explicit successor store comment or reconstruct from `FUN_004cb270` + stack shadow (dual already gaps successor English).
2. Clean splice path is a simplified MSVC shape; dual/raw remain authoritative for tight RB edge cases.

### Unit C dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit D — `0x004cbb60` StdTree_InsertAndRebalance_Isnil29_Inferred (WQ9E-E)

### Body / ABI / CF seal (independent — dual + raw + bulk)

| Claim | Independent result |
|---|---|
| Body `0x004cbb60`–`0x004cbd4b` exclusive (**491 B** / `0x1EB`); terminal **`C2 10 00`** | **Confirmed** — dual exit hex `83c450c21000…` |
| **`__thiscall`**; stack `outIt`, `addLeft`, `where`, `value`; **RET 0x10** | **Confirmed** — bulk decompile 5-arg thiscall |
| `size > 0xAAAAAA8` → `"map/set<T> too long"` / `DAT_00acc388` | **Confirmed** — bulk |
| Buynode **`FUN_005a2de0`** (not Val12 buynode); size++; link; RB while parent red; root black; `*outIt` | **Confirmed** — bulk |
| `addLeft==0` → **right** link | **Confirmed** — bulk `param_3=='\\0'` → `param_4[2]=new` |
| isnil@+0x29 / color@+0x28 / node 0x30 | **Confirmed** — dual + peer buynode notes; inlined rotate tests `+0x29` |
| Callers `FUN_004cbe20` / `004cbee0` / `004cc220` (11 xrefs) | **High** — dual sealed |
| Always-insert (parent owns uniqueness) | **Confirmed** — no key compare in body |
| Do not merge with Val12 insert `0x005ae4e0` (max `0x15555553`, isnil@+0x19) | **Confirmed** |
| Product demangle / 6-dword field English | **Open** |

### Material finding — clean plate collision / clobber

**Sealed dual CF for `0x004cbb60` stands in raw + A/B + function record.**  
**The claimed clean plate does not currently document this VA.**

| Evidence | Detail |
|---|---|
| Claimed clean path (WQ9E-E report + `aa_004cbb60` function record + `FUN_004cbb60.cpp` redirect) | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil29_Inferred.cpp` |
| Actual clean plate header | Stable ID **`aa_00406c40`**; Address **`0x00406c40`–`0x00406dd5`** (**405 B**); Wave **WQ9E-G**; buynode **`FUN_00407e30`** |
| WQ9E-E unit needs | Address **`0x004cbb60`** (**491 B**); buynode **`FUN_005a2de0`** |
| Scaffold twin | `FUN_004cbb60.cpp` is a **stub redirect** to the shared plate (no own CF body) |

This is a **name collision** between two distinct always-insert isnil29 clones:

| VA | Body | Buynode | Dual owner |
|---|---|---|---|
| `0x00406c40` | 405 B | `FUN_00407e30` | WQ9E-G (currently owns clean file) |
| `0x004cbb60` | 491 B | `FUN_005a2de0` | WQ9E-E (lost clean plate content) |

Both legitimately use the structural name `StdTree_InsertAndRebalance_Isnil29_Inferred`, but the **un-suffixed clean path can hold only one**. Prior waves use VA-suffixed cleans for twin clones (e.g. `StdTree_EraseAndRebalance_Val12_005e15a0.cpp`).

**Impact:** AutoCore porting or parent merge that trusts the clean path for `aa_004cbb60` would wire the **wrong buynode / wrong body size / wrong parent context**. Dual **raw** remains correct for `0x004cbb60`.

**Recommended parent/dual follow-up (not done by this ADV):**

1. Emit VA-disambiguated clean: e.g. `StdTree_InsertAndRebalance_Isnil29_004cbb60.cpp` (and optionally rename/keep `…_00406c40` for G).
2. Fix `aa_004cbb60` function record + dual report file table + `FUN_004cbb60.cpp` redirect.
3. Keep shared **role name** in NAMING_REGISTRY with **VA peer list** (do not merge VAs).

### Adversarial attacks (insert CF — dual seals)

| # | Attack | Result |
|---|---|---|
| 1 | This is erase twin | **Fails** — length guard, buynode, size++ |
| 2 | Val12 insert clone | **Fails** — isnil@+0x29; max `0xAAAAAA8`; buynode `005a2de0` |
| 3 | Aggro/GetTarget product role | **Fails** — scaffold narrow; structural insert |
| 4 | Uniqueness compare inside unit | **Fails** — always-insert |
| 5 | `addLeft==0` means left | **Fails** — links **right** |
| 6 | RET 4/8 | **Fails** — **ret 0x10** |
| 7 | Clean plate at claimed path is authoritative for this VA | **Succeeds as attack** — plate is `00406c40` |
| 8 | Product demangle sealed | **Fails** |

### Unit D dual quality

**PASS-WITH-FINDINGS** — keep dual verdict **`accept-with-gaps`** for **CF/ABI seals** (raw + A/B), but **reject the clean-path claim** until a VA-disambiguated clean is restored for `0x004cbb60`.

---

## Cross-unit dual report quality

| Check | WQ9E-C | WQ9E-E |
|---|---|---|
| Dual report verdicts match A/B | **Yes** — both **accept** | **Yes** — both **accept-with-gaps** |
| Terminal false honesty | **Yes** | **Yes** |
| OWN scope discipline | **Yes** (palette + band only) | **Yes** (erase + insert only) |
| Tool discipline | **Yes** — no `disassemble_bytes` | **Yes** |
| Decompiler artifact honesty | **Yes** — void/EAX; unsigned band trick | **Yes** — false noreturn delete; epilogue size-- |
| Odd behavior preserved | white mode unused; mode1=default | addLeft polarity; inlined rotate; decomp noreturn |
| Clean sources meaningful | **Yes** (both UI cleans own their VAs) | Erase **yes**; insert **no** (collision) |
| Peer non-merge hygiene | palette ≠ band ≠ resolver | isnil29 ≠ Val12; erase ≠ insert |
| AutoCore port notes | Accurate palette/band ABI | Accurate CF notes; **clean path unsafe for 004cbb60** |

### Independent overall verdict

| Unit | Dual verdict | ADV verdict |
|---|---|---|
| `aa_00930f40` Ui_NameColorPalette_WriteArgb_Inferred | accept | **PASS — keep accept** |
| `aa_0092d580` Ui_NameColorLevelBand_CopyFloat4_Inferred | accept | **PASS — keep accept** |
| `aa_004cb740` StdTree_EraseAndRebalance_Isnil29_Inferred | accept-with-gaps | **PASS — keep accept-with-gaps** |
| `aa_004cbb60` StdTree_InsertAndRebalance_Isnil29_Inferred | accept-with-gaps | **PASS-WITH-FINDINGS** — CF seals hold; **clean plate mis-bound to `0x00406c40`** |

### Spot-check rollup

**Overall WQ9E-C + WQ9E-E ADV: PASS-WITH-FINDINGS.**

- **WQ9E-C:** fully seals under independent review; no sealed-claim failures.
- **WQ9E-E erase:** seals under independent review; epilogue decomp gap correctly owned.
- **WQ9E-E insert:** dual **raw/A/B CF** seals; **artifact hygiene fails** on shared clean filename collision with WQ9E-G `0x00406c40`. Parent merge must not treat `StdTree_InsertAndRebalance_Isnil29_Inferred.cpp` as the `0x004cbb60` body until disambiguated.

**No dual rewrite performed by this ADV** (per charter). Terminal remains **false**.

---

## Process

- Independent ADV verifier; **not** WQ9E-C / WQ9E-E dual author.
- Evidence: dual reports, A/B, raw/annotated/clean/function records; bulk decompile captures for waveE 047/596/599; dual-appended byte seals.
- **No** `disassemble_bytes`. **No** parent ledger edits. **No** dual file edits. **No** Launcher.
- Output: `docs/reconstruction/reviews/ADV_wq9e_spotcheck_ui_erase.md` (this file).

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
