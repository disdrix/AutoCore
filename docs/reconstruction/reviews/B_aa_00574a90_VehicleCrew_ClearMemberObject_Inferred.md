# Review B (skeptical / adversarial): `aa_00574a90` VehicleCrew_ClearMemberObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574a90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00574a90_VehicleCrew_ClearMemberObject_Inferred.md` |
| **Agent** | WQ9D-G OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on behavior/ABI; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Full roster remove (free slot for insert) | **Falsified** — COID pair untouched; insert free-scan needs `0xFFFFFFFF` |
| 2 | `FUN_00520330` this = crew host | **Falsified** — ECX remains candidate; callee writes `candidate+0xCB0` |
| 3 | Compares full TFID_16 | **Falsified** — two dwords only (+0x164/+0x168) |
| 4 | Unbounded scan | **Falsified** — hard stop `i > 3` |
| 5 | Decrements `+0x1D8` | **Falsified** — no store to count field |
| 6 | Many skill gather callers | **Falsified** — sole xref is `Client_ClearObjectReferences` |
| 7 | This is faction / friendly-fire | **Falsified** — pure COID table + CB0 unlink |
| 8 | Product name retail-known | **Unproven** — `_Inferred` |
| 9 | Runtime Confirmed | **Rejected** — no Launcher |
| 10 | Null candidate undefined crash only | **Open residual** — no early null check (unlike Contains); sole caller gates vtbl+0x1dc non-null |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| AL bool / RET 4 | **Confirmed** | Wrong port ABI |
| Partial clear (object* + CB0 only) | **Confirmed** | Porting as full remove breaks insert free-scan |
| ECX=candidate on setter | **Confirmed** | Writing host+0xCB0 corrupts wrong object |
| 4×0x10 @ +0x198 | **Confirmed** | Roster false miss |
| “VehicleCrew” English | **High structural / Inferred product** | Rename if RTTI |
| Intent of leaving COID | Open | Design vs incomplete free |

---

## 3. Cross-check

```
005749d0 Contains: COID match → AL bool; leaf
005755b0 Insert:  !Contains; free FFFFFFFF; write COID+obj*; count++; SetCB0(host)
00574a90 Clear:   COID match → obj*=0; SetCB0(0); no COID free
00520330:         *(this+0xCB0)=arg; ret 4
00944d50:         sole caller on object teardown
0058a810 0xb:     uses Contains, not Clear
```

**Attack on “clear frees slot like erase”:** insert free condition is COID pair all-bits-one; this unit never writes COID.

**Attack on “setter this is host”:** insert decompile shows `FUN_00520330(param_1)` meaning value=host with this=member; clear passes value=0 with this=candidate — symmetric back-link.

---

## 4. Surviving contract for AutoCore

```
bool VehicleCrew_ClearMemberObject_Inferred(CrewHost* host, Object* candidate) {
  // COID from SharedBase +0x164/+0x168
  for (int i = 0; i < 4; i++) {
    if (slot_coid_match(host, i, candidate)) {
      host_object_ptr(host, i) = nullptr;   // +(i+0x1A)*0x10
      candidate->crewHostAtCB0 = nullptr;     // +0xCB0
      return true;
    }
  }
  return false;
}
```

Port notes:
- Do **not** implement as full Remove (no FFFFFFFF, no count--).
- Pair with Contains/Insert for roster CRUD; this unit is destroy-path partial unlink.
- Sole client call is ClearObjectReferences — skill gather uses Contains only.

---

## 5. Gaps

1. Product English / demangle.  
2. Design intent of COID leave-behind.  
3. Null-candidate behavior if called without gate.  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**.
