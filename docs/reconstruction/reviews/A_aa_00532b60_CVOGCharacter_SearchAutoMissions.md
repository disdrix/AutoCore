# Review A (reconstruction fidelity): `aa_00532b60` CVOGCharacter_SearchAutoMissions

| Field | Value |
|---|---|
| **Stable ID** | `aa_00532b60` |
| **VA** | `0x00532b60` |
| **Canonical name** | `CVOGCharacter_SearchAutoMissions` |
| **Review date** | `2026-07-29` (residual pass 2) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live assembly seals) |
| **Counterpart** | `reviews/B_aa_00532b60_CVOGCharacter_SearchAutoMissions.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present and residual-strengthened** (A + B; supersedes 2026-07-23 ESI residual + pass-1 gaps) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Walk the **global mission-definition table** and auto-grant every eligible auto-mission on the local character in one scan:

1. Profile enter `"CVOGCharacter::SearchAutoMissions"` (`FUN_00786a00` / string `@0x009cff4c`).
2. Resolve mission-def **wrapper** via `FUN_0053fff0` (`ECX = DAT_00b041fc` → lazy `*(owner+0xf18)`); bail if wrapper null.
3. Lock hash (`*wrapper` → hash `+0x1d`); traverse nodes (`EDI` cursor: first `hash+0x14`, then `node+0x14`; value `node+0x8`).
4. Candidate filter: **`u16` at missionDef `+0xF8` != 0** (decompiler dword-index `0x3e`).
5. Skip if already in active hash `character+0x540` or completed `character+0x538` (manual bucket walk; payload `@node+0x8` must be non-null to skip).
6. `CheckMissionRequirements(ECX=def, stack=character)`; if return **0**, `GiveMission(ECX=character, stack=*def)`.
7. **After grant (or skip), continue** — `JMP LAB_00532c00` (multi-grant possible).
8. Unlock hash `+0x1d`; profile leave.

**Calling convention:** MSVC character in `ECX` at entry; body stashes in **`EBP`** (`MOV EBP,ECX` @ `0x00532b78`). Void; no stack formals (`RET` after SEH teardown).

| Slot | Role | Evidence |
|------|------|----------|
| `this` / entry `ECX` | `CVOGCharacter*` | Stashed `EBP`; `+0x540` / `+0x538` loads |
| return | void | Early/unlock returns only |

**Side effects:** full `GiveMission` for each pass (active hash insert, toast **not** taken when auto flag nonzero, etc.). Read-only on skip-path hashes. No direct instance-completed (`+0x53c`) walk. GiveMission return value ignored.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00532b60_CVOGCharacter_SearchAutoMissions.md` |
| Annotated | `docs/reconstruction/raw/aa_00532b60_CVOGCharacter_SearchAutoMissions.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_SearchAutoMissions.cpp` |
| Function record | `docs/reconstruction/functions/aa_00532b60_CVOGCharacter_SearchAutoMissions.md` |
| System map | `docs/reconstruction/systems/missions-progression.md` |
| Callee duals | `aa_005462b0` CheckMissionRequirements; `aa_005327c0` GiveMission |
| Live re-decompile | Ghidra MCP `decompile_function` @ `0x00532b60` (2026-07-29) — **CF ≡ raw** |
| Table accessor | `batch_decompile` `FUN_0053fff0` @ `0x0053fff0` |
| Level-apply caller | `batch_decompile` `FUN_00533220` @ `0x00533220` |
| Live assembly | Ghidra `get_assembly_context` gate / Requirements / GiveMission / unlock / callers |
| Xrefs | `get_function_xrefs` — 4 sites |
| Scratch | `tmp/a_00532b60.md` |

**Not performed:** `disassemble_bytes` bulk listing, Launcher, live auto-grant capture, bit-exact diff.

---

## 3. Decisive framing (assembly-backed)

### 3.1 Requirements call (seals `unaff_ESI`)

```
00532cd0  PUSH EBP           ; character*
00532cd1  MOV ECX, ESI       ; missionDef*
00532cd3  CALL 0x005462b0    ; CheckMissionRequirements
00532cd8  TEST EAX, EAX
00532cda  JNZ LAB_00532c00   ; non-zero → no grant
```

| Prior claim | Correction | Confidence |
|---|---|---|
| `CheckMissionRequirements(def, this, unaff_ESI)` three formals | **Two formals:** `thiscall` ECX=def, stack0=character | **High** |
| `unaff_ESI` is a live third context pointer | **Falsified** — ESI holds mission def; never pushed as stack1 | **High** |

### 3.2 GiveMission call + multi-grant continue

```
00532ce0  MOV EAX, [ESI]     ; *missionDef = id
00532ce2  PUSH EAX
00532ce3  MOV ECX, EBP       ; character
00532ce5  CALL 0x005327c0
00532cea  JMP LAB_00532c00   ; continue traversal
```

| Claim | Confidence |
|---|---|
| GiveMission `__thiscall` character + mission id | **High** |
| Multiple grants possible in one Search call | **High (static)** — unconditional JMP to loop head |
| GiveMission return consulted | **No** — ignored |

### 3.3 Auto flag field

```
00532c56  CMP word ptr [ESI+0xF8], 0
00532c5e  JZ LAB_00532c00    ; skip
```

| Representation | Value |
|---|---|
| Byte offset | **`+0xF8`** (`u16`) |
| Decompiler form | `(short)((uint*)def)[0x3e]` (`0x3e * 4 = 0xF8`) |
| Candidate when | **!= 0** |
| GiveMission toast when | **== 0** (same field; opposite sense) |

### 3.4 Mission-table accessor (`FUN_0053fff0`)

Live callee body (`0x0053fff0`):

```c
// ECX = DAT_00b041fc (owner)
if (*(owner + 0xf18) == 0) {
  // operator_new(0x10) + FUN_0060b870 ctor → store at owner+0xf18
}
return *(owner + 0xf18);   // wrapper*
```

Search usage:

| Step | Asm / CF | Meaning |
|---|---|---|
| Load owner | `MOV ECX,[0x00b041fc]` | Global table owner |
| Call | `CALL FUN_0053fff0` | Lazy wrapper at `owner+0xf18` |
| Null check | `TEST EAX,EAX` early | No table |
| Hash root | `MOV ESI,[EAX]` / `MOV EAX,[EAX]` | **`*wrapper` is the CNDHash** |
| Lock | `byte [hash+0x1d]` | Shared traversal lock |

Product names for owner / wrapper / ctor open; **layout + role High**.

### 3.5 Active/completed hash probe (layout)

```
MOV EAX, [EBP+0x540]     ; or +0x538
MOV EDX, [EAX+0x8]       ; mask
MOV ECX, [ESI]           ; key = *def
MOV EAX, [EAX+0x10]      ; bucket array
AND EDX, ECX
MOV EDX, [EAX+EDX*4]
MOV EAX, [EDX+0x4]       ; chain head
; walk: next [node+0xc], key [node+0x10], skip if [node+0x8] != 0
```

| Offset | Role | Confidence |
|---|---|---|
| hash `+0x8` | mask | **High** |
| hash `+0x10` | bucket array | **High** |
| node `+0x4` (bucket) | chain head | **High** |
| node `+0xc` | next | **High** |
| node `+0x10` | key | **High** |
| node `+0x8` | payload (must be non-null to skip) | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function boundary @ `0x00532b60` | **High** | Named profile string @ `0x009cff4c` |
| Table lock/traverse/unlock `+0x1d` / `+0x14` / `+0x8` | **High** | Shared hash protocol + error strings |
| `FUN_0053fff0` → `owner+0xf18` wrapper; hash = `*wrapper` | **High** | Live callee + call-site deref |
| Auto flag `u16` @ def **`+0xF8`** | **High** | Live CMP |
| Active skip `character+0x540` | **High** | Live load |
| Completed skip `character+0x538` | **High** | Live load |
| Instance-completed `+0x53c` consulted here | **No** | Absent from body |
| Requirements return **0 = pass / grant** | **High** | `TEST/JNZ` + callee dual |
| GiveMission id = `*def` | **High** | Live `[ESI]` |
| Multi-grant per scan | **High (static)** | `JMP LAB_00532c00` after Give |
| `unaff_ESI` third arg | **Falsified** | Assembly seal |
| Toast field relationship (`+0xF8`) | **High** | Cross-unit GiveMission dual |
| English name of `+0xF8` | **Probable** | Auto/silent-assign; no body string |
| Callers LevelUp/Down/CompleteObjective/`FUN_00533220` | **High** sites | All local-gate `…+0xa8`→`+0x7e` |
| Local gate is bare `character+0x7e` | **Oversimplified** | MI path: `*(*( *(this+4)+4 ) + this + 0xa8 ) + 0x7e` |
| CompleteObjective dirty `\|0x10` @ `+0x634` | **High** | After Search only at that site |
| Runtime schedule completeness | **Open** | Login/zone not in static xref set |
| Clean ≡ raw CF | **High** | Live decompile match; prototype corrected |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Profile enter | **Yes** |
| Null table early return | **Yes** |
| Lock + infinite traverse until null node | **Yes** |
| Auto flag filter `@+0xF8` | **Yes** |
| Active / completed skip | **Yes** |
| Requirements → GiveMission on 0 | **Yes** |
| Continue after grant | **Yes** (clean loop) |
| Unlock + profile leave | **Yes** |
| No third Requirements stack arg | **Yes** |

---

## 6. Callers (static schedule)

| Caller | Call site | Local gate | After-call |
|---|---|---|---|
| `CVOGCharacter_LevelUp` `0x00532d30` | `0x0053303a` | `*(*(base)+this+0xa8)+0x7e` | continues level-up epilogue |
| `CVOGCharacter_LevelDown` `0x005330e0` | `0x00533213` | same | epilogue/ret |
| `CVOGReaction_CompleteObjective` `0x00533f90` | `0x00534851` | same | **`OR [char+0x634], 0x10`** then return 1 |
| `FUN_00533220` (level-set / stat-recalc) | `0x00533586` | same | vehicle combat-pool path |

**`FUN_00533220` role (High, product name open):** writes level (`param_1[0x1b2]`), applies experience-table bonuses under flag bits, skill re-eval, then Search when local. Not a free-standing “login search.”

Porting rule: client only auto-searches for **local** character objects (gate above). Server mirrors should re-evaluate eligibility on level/complete events without inventing extra call sites from this unit.

---

## 7. Gaps

1. Retail English name for def `+0xF8` (auto-assign / silent grant).
2. Product names: `FUN_0053fff0`, profile enter/leave, `FUN_00533220`, `DAT_00b041fc` owner type.
3. Product type of object at relative `+0xa8` (only `+0x7e` byte used here).
4. Whether login/zone paths call Search via another thunk (not in current xref set of 4).
5. Instance-completed autos: not filtered here; GiveMission may still reject via `+0x53c` for some defs.
6. Runtime / bit-exact / differential open.

**Verdict:** Auto-award spine CF + ABI + multi-grant + table getter sealed. **accept-with-gaps.**
