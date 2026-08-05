# Review B (skeptical / adversarial): `aa_00532b60` CVOGCharacter_SearchAutoMissions

| Field | Value |
|---|---|
| **Stable ID** | `aa_00532b60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (residual pass 2) |
| **Counterpart** | `reviews/A_aa_00532b60_CVOGCharacter_SearchAutoMissions.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present and residual-strengthened** (A + B modern pair) |
| **Verdict** | **accept-with-gaps** on grant spine + ABI + multi-grant; **reject** listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Uses `HasCompletedMission` API for completed skip | **Falsified** — manual bucket walk of `+0x538` only; no call to `aa_0052aa20` |
| 2 | Skips instance-completed missions (`+0x53c`) | **Not shown in this body** — may still reject inside GiveMission for some defs |
| 3 | CheckMissionRequirements non-zero means pass | **Falsified** — grant only when return **== 0** (`TEST/JNZ`) |
| 4 | Walks character auto list only | **Overstated** — walks **global** mission table (`FUN_0053fff0` / `DAT_00b041fc`); filter is def flag |
| 5 | `unaff_ESI` is a reliable third arg / context object | **Falsified** — call site is `PUSH EBP; MOV ECX,ESI; CALL Requirements`; ESI is **mission def** |
| 6 | Auto flag is byte offset `+0x3e` | **Falsified as byte** — live `CMP word ptr [ESI+0xF8]`; decompiler `0x3e` is **dword index** |
| 7 | `def+0xF8` toast gate is a different field than auto | **Falsified relationship** — same word: toast when **0**, auto when **!=0** |
| 8 | GiveMission called as free function with id only | **Misleading raw** — live `ECX=character`, stack=id |
| 9 | Runs for every character on level-up | **Falsified** — all four xrefs gate on local object `+0x7e` via `…+0xa8` path |
| 10 | Local flag is bare `character+0x7e` | **Oversimplified** — access is `*(*( *(this+4)+4 ) + this + 0xa8 ) + 0x7e` |
| 11 | At most one mission granted per Search call | **Falsified (static)** — after GiveMission: `JMP LAB_00532c00` continues scan |
| 12 | `FUN_0053fff0()` is a free nullary returning the hash | **Misleading** — `ECX=DAT_00b041fc`; returns **wrapper** at `owner+0xf18`; hash is `*wrapper` |
| 13 | Search checks GiveMission return before continuing | **Falsified** — return ignored; always continues |
| 14 | Package is bit-exact / runtime complete | **Fail** — static dual only |

---

## 2. Decisive dataflow (raw + live residual-2)

```
profile enter "CVOGCharacter::SearchAutoMissions"
wrapper = FUN_0053fff0(DAT_00b041fc)   // lazy *(owner+0xf18)
if !wrapper: profile leave; return
hash = *wrapper

lock hash (+0x1d)
for each node in table chain (+0x14 / value +0x8):
  def = node.value
  if word(def+0xF8) == 0: continue
  id = *def
  if active_hash(+0x540) hit with payload: continue
  if completed_hash(+0x538) hit with payload: continue
  if CheckMissionRequirements(def, character) == 0:
    GiveMission(character, id)   // return ignored
  // fall through / JMP → next node (multi-grant)
unlock; profile leave
```

Live decompile body **matches** frozen raw CF. Assembly **corrects** decompiler residual formals only. Multi-grant is **not** a decompiler artifact — explicit `JMP` after GiveMission.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Grant only when requirements return 0 | **High** | Auto-spam or never grant |
| Active/completed skip hashes `+0x540`/`+0x538` | **High** | Duplicate grants / blocked autos |
| Global table iteration via `owner+0xf18` | **High** | Wrong mission set scanned |
| Auto flag `@+0xF8` (u16) | **High** | Wrong missions auto |
| Multi-grant per call (static) | **High** | Server port may under-grant if “first only” |
| ESI as third context | **Falsified** | Invented ABI |
| Requirements two-formal thiscall | **High** | Stack pollution / wrong this |
| Local-only callers (`+0xa8`→`+0x7e`) | **High** | Server double-fires on NPCs |
| English auto-field name | **Tentative** | Docs naming only |
| Complete login/zone schedule | **Open** | Missed auto-grant triggers |
| Runtime / differential | **Open** | Residual parity risk |

---

## 4. Offset / ABI attack checklist

| Item | Attack | Result |
|------|--------|--------|
| Active `+0x540` | Invented? | **No** — `MOV EAX,[EBP+0x540]` |
| Completed `+0x538` | Invented? | **No** — `MOV EAX,[EBP+0x538]` |
| Auto `+0xF8` | Invented? | **No** — `CMP word [ESI+0xF8],0` |
| Dword index `0x3e` as byte offset | Compatible? | **No** — would be wrong field |
| Third Requirements arg | Live? | **No** — not pushed |
| `HasCompletedMission` reuse | Present? | **No** |
| `+0x53c` skip | Present? | **No** in this unit |
| Toast field independence | Different offset? | **No** — same `+0xF8` / index `0x3e` |
| Single-grant assumption | Forced exit after Give? | **No** — `JMP LAB_00532c00` |
| `FUN_0053fff0` returns hash directly | `*wrapper` needed? | **Yes** — unlock does `MOV EAX,[EAX]` then `+0x1d` |
| Hash mask/buckets | Invented? | **No** — `+0x8` / `+0x10` probe asm |

---

## 5. Surviving contract for AutoCore

```
SearchAutoMissions(character)   // client local-only at call sites
  wrapper = EnsureMissionDefTable(DAT_00b041fc)  // *(owner+0xf18)
  scan *wrapper hash of all mission defs
  candidate iff u16(def+0xF8) != 0
  skip if active(+0x540) or completed(+0x538) hit with payload
  if CheckMissionRequirements(def, character) == 0:
      GiveMission(character, *def)   // may grant many times per call
  does not consult HasCompletedMission helper
  does not walk instance-completed (+0x53c)
  does not itself insert mission state beyond GiveMission
  does not use GiveMission's return value
```

**Porting rules:**

1. Do **not** invent a third context argument for Requirements from this call site.
2. Do **not** treat `+0xF8 == 0` defs as auto-assign (those take GiveMission toast path instead).
3. Do **not** claim this unit re-grants completed missions solely because `+0x53c` is omitted — GiveMission still has completed gates.
4. Do **not** implement “grant first matching only” — static CF continues after each grant.
5. Server auto-award should key off the same events (level change, objective complete, character level-apply) with eligibility equivalent to Requirements, not on remote/NPC objects.
6. Table access is via owner global + `+0xf18` wrapper, not a free-standing “auto list” on the character.

---

## 6. Open questions

1. Retail symbol for def `+0xF8` (auto-assign flag vs mission type enum).
2. Whether any non-xref path schedules Search (e.g. indirect call not seen in Ghidra xrefs).
3. Product type of `DAT_00b041fc` / wrapper / `FUN_00533220`.
4. Runtime proof of multi-grant counts in one scan.
5. Bit-exact / differential package seal.

**Verdict:** Accept auto-scan CF + assembly ABI + multi-grant + table getter; **reject** `unaff_ESI` residual, byte-`+0x3e` misread, single-grant myth, and bare-`character+0x7e` shortcut; keep English field name and runtime schedule as open.
