# Review A (reconstruction fidelity): `aa_00547920` MissionDef_EnsureXmlLoaded

| Field | Value |
|---|---|
| **Stable ID** | `aa_00547920` |
| **VA** | `0x00547920` |
| **Canonical name** | `MissionDef_EnsureXmlLoaded` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00547920_MissionDef_EnsureXmlLoaded.md` |
| **System** | missions-progression (mission def lazy XML hydrate) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Lazy-load mission definition XML into a mission-def object** (`this` = mission def):

1. Gate: if **`byte this+0x168`** already set (`param_1[0x5a]` as `int*` → dword index `0x5a` ×4 = **0x168**) → **return immediately** (already loaded).
2. Else set `this+0x168 = 1`, then open path via `"%s%S.xml"` (`_snprintf` + `NDXml_OpenTaggedDocument`).
3. On open failure → log (`FUN_007a4480`) + cleanup (`FUN_007989b0`) + return.
4. On success: iterate document roots; match mission id `*this` against parsed entry; on id mismatch log + break.
5. Require child nodes; else log **`"Mission lacking child nodes %s"`**.
6. Walk children by wide tag name (`_wcsicmp`):
   - **`Objective`** → `FUN_00547050` (objective parse/attach)
   - **`CoreMission`** → parse flag path; store; set **`this+0x169 = 0`**
   - **`Title`** → `FUN_00545f80` after string convert
   - **`Internal`** → `FUN_00545f10`
   - **`Description`** → `FUN_00545ff0`
   - **`OneLineAccept`** → `FUN_00546060`
   - **`OneLineReject`** → `FUN_005460d0`
   - **`NotCompleteText`** → `FUN_00546140`
   - **`CompleteText`** → `FUN_005461b0`
   - **`FailText`** → `FUN_00546220`
   - unknown tags skipped (`goto` continue)
7. Release COM/BSTR/XML resources; SEH frame present.

**Not** a free-function taking only stack 0/1 — decompiler `__fastcall`/`void` display is incomplete framing; callers always set **ECX = mission def**. Residual call sites push a stack arg (0 or 1) whose body consumption is **Tentative** (not recovered as a formal in decompile).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00547920_FUN_00547920.md` |
| Annotated | `docs/reconstruction/raw/aa_00547920_FUN_00547920.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00547920.cpp` |
| Function record | `docs/reconstruction/functions/aa_00547920_FUN_00547920.md` |
| Fresh decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x00547920` |
| Callers (19 xrefs) | GiveMission, CompleteObjective, ApplyCreateFromPacket, journal/UI dialogs, interact eval, etc. |
| Prior residual | `reviews/a_005327c0.md` (XML ensure-load seal) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = mission def XML ensure / lazy load | **High** | gate + path + tag parse |
| `this` = mission def (ECX) | **High** | callers MOV ECX,def; compares `*param_1` to parsed id |
| Loaded flag byte at **`+0x168`** | **High** | `param_1[0x5a]` as int* = byte @ 0x168 |
| Early-out if already loaded | **Confirmed** | outer if |
| Sets flag **before** open (optimistic load-once) | **High** | write 1 then open — failed open still leaves flag set |
| Path format `"%s%S.xml"` | **Confirmed** | string |
| `NDXml_OpenTaggedDocument` open | **High** | named callee |
| Tag set Objective/CoreMission/Title/…/FailText | **Confirmed** | `_wcsicmp` chain |
| Field setters `FUN_00545f80`…`FUN_00546220` | **High** (role map) | one setter per text tag |
| Objective attach `FUN_00547050` | **High** (role) | |
| CoreMission clears/writes `+0x169` | **High** | body `*(this+0x169)=0` |
| Id mismatch aborts parse loop | **High** | compare `local_558 != *param_1` |
| Missing children logs fixed English string | **Confirmed** | |
| Stack arg 0/1 semantics | **Tentative** | call sites push; not in decompiler formals |
| Decompiler garbage wide strings on log path | **Confirmed noise** | stack corruption display; ignore as product text |
| void return | **High** | no useful EAX contract recovered |
| clean ≡ raw ≡ live major CF | **High** | large body; scaffold matches live |
| Full arg recovery for every COM vcall | **Open** | unaff_ESI/EDI noise |

---

## 4. Control flow (recovered)

```c
// void __thiscall MissionDef_EnsureXmlLoaded(MissionDef *def /*, stack mode? */)

if (def->xmlLoaded /* +0x168 */) return;

def->xmlLoaded = 1;   // set BEFORE open (load-once even if open fails)

// build path "%s%S.xml"; NDXml_OpenTaggedDocument()
if (open failed) { log; cleanup; return; }

// for each top-level mission entry in doc:
//   resolve entry; if entry missionId != *def → log; break
//   if no children → log "Mission lacking child nodes %s"; break
//   for each child:
//     tag Objective        → parse objective (FUN_00547050)
//     tag CoreMission      → parse; def+0x169 = 0
//     tag Title            → FUN_00545f80
//     tag Internal         → FUN_00545f10
//     tag Description      → FUN_00545ff0
//     tag OneLineAccept    → FUN_00546060
//     tag OneLineReject    → FUN_005460d0
//     tag NotCompleteText  → FUN_00546140
//     tag CompleteText     → FUN_005461b0
//     tag FailText         → FUN_00546220
//     else                 → skip
// cleanup XML/COM; return
```

### Flag byte math

| Ghidra form | Byte offset | Role |
|---|---|---|
| `(char)param_1[0x5a]` | `0x5a * 4 = 0x168` | xml loaded |
| `*(this + 0x169)` | `0x169` | CoreMission-related byte (cleared on tag) |

---

## 5. Callers (sample; 19 xrefs)

| Domain | Examples |
|---|---|
| Grant / complete | `CVOGReaction_GiveMission` (push 1 then maybe 0 if still unloaded), `CVOGReaction_CompleteObjective` |
| Create | `CVOGCharacter_ApplyCreateFromPacket` |
| UI / journal | `Client_UpdateMissionJournal`, `Client_ShowNpcMissionDialogUI`, dialog prepare |
| Interact | `CVOGObject_EvalInteractStateFromChildren`, `CVOGObject_EvalOfferableMissionInteractState` |

**High:** any consumer that needs hydrated text/objectives on a def calls this first. Free call sites with only stack constants are **misframed** without ECX=def.

---

## 6. Param renames

| Raw | Preferred | Evidence |
|---|---|---|
| `param_1` | `missionDef` | ECX; `*this` id compare; +0x168 flag |
| (stack, elided) | `mode` / force? | callers push 0/1; **Tentative** |
| child tag strings | keep English | `_wcsicmp` literals |

Setter callees remain `FUN_*` until dualed.

---

## 7. Gaps / open questions

1. **Stack 0 vs 1** product meaning (force reload? partial? log level?) — **Tentative**; body does not show a formal.
2. Whether failed open leaving `+0x168=1` is intentional permanent soft-fail (cannot retry) — **High** as written; product intent Open.
3. Path prefix `%s` / stem `%S` source registers (decompiler stripped args to snprintf).
4. Exact COM interfaces for XML node vcalls (unaff_* noise).
5. Setter function duals for Title/Description/… field offsets on def.
6. Runtime XML load capture / bit-exact deferred.
7. Garbled decompiler log wide-strings are not product copy.

**Verdict:** **accept-with-gaps** — ensure-load role, +0x168 gate, tag matrix, and ECX=def sealed High; stack mode + snprintf operands residual.
