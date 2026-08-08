# Review B (skeptical / adversarial): `aa_00520330` Object_SetCrewHostBackLink_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520330` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00520330_Object_SetCrewHostBackLink_Inferred.md` |
| **Agent** | WQ9E-D OWN-ONLY dual |
| **Verdict** | **accept** on behavior/ABI; product name Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler `FUN_00520330(host)` means host+0xCB0 written | **Falsified** — thiscall **ECX is member**; stack is host/null; body writes **this+0xCB0** |
| 2 | Field is TFID-16 | **Falsified** — 4-byte pointer store only |
| 3 | Non-trivial logic / validation | **Falsified** — pure store leaf |
| 4 | `ret` without stack cleanup | **Falsified** — `C2 04 00` = **ret 4** |
| 5 | Only used by Insert | **Falsified** — 7 callers including Clear/wipe/load/leave |
| 6 | Scaffold VOG_DEBUG_STOP name is product | **Falsified as product** — Insert assert path only; this is back-link setter |
| 7 | Product name retail-known | **Unproven** — `_Inferred` |
| 8 | Runtime Confirmed | **Rejected** — no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Store offset `+0xCB0` | **Confirmed** | Crew graph desync |
| Thiscall + ret 4 | **Confirmed** | ABI crash |
| Insert/Clear polarity (host vs 0) | **Confirmed** | via dualed callers |
| “Crew host” English | **High structural** | Rename only |
| Exclusive ownership of `+0xCB0` | Open | Other systems |

---

## 3. Cross-check

```
005755b0 Insert: ecx=member, arg=host → member+0xCB0 = host
00574a90 Clear:  FUN_00520330(0) with member this → clear back-link
00575200 wipe:   for each slot object*, set back-link 0
0082fb30 convoy: reads *(local+0xCB0) as Contains host
0058a810 mode 0xb: Contains(*(veh+0xCB0), cand)  // field consumer
```

**Attack on “setter writes host field on crew host”:** bytes and call setups agree it writes the **member** object’s `+0xCB0`.

---

## 4. Surviving contract for AutoCore

```c
// Object partial:
//   +0xCB0  void* crewHost;  // set on insert; cleared on leave/wipe

void Object_SetCrewHostBackLink_Inferred(Object* self, void* crewHostOrNull) {
  self->crewHost = crewHostOrNull; // @ +0xCB0
}
```

**Verdict:** **accept** — no CF reject; residual is naming only.
