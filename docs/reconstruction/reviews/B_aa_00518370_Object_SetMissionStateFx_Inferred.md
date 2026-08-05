# Review B (skeptical / adversarial): `aa_00518370` Object_SetMissionStateFx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518370` |
| **VA** | `0x00518370` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W30-H) |
| **Counterpart** | `reviews/A_aa_00518370_Object_SetMissionStateFx_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/role; product name residual |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler void / missing stack clean | Epilogue **`C2 04 00`**; callers pass one int | **thiscall + stack formal** |
| 2 | "FailMissionNotify" implies mission-fail side effect | Nested dual: `0x004149d0` is **Vector_PushDword** (historical name) | **Not mission-fail** |
| 3 | State 3 loads an FX variant | Branch is `if (2 < state)` audio-only before 0/1/2 cases | **No FX for state>2** |
| 4 | Teardown clears bit2 permanently | Body **ors** bit2 after teardown (W29-N clears it) | **Re-arm intentional** |
| 5 | `FUN_00516930(1)` means ECX=1 | Keep ECX=this; push 1 unread by callee (W29-N) | **this + stack 1** |
| 6 | Prior name SpawnObject-only | 5 distinct CODE callers including progress thunks | **Broader than spawn** |
| 7 | Product name in binary | None | **`_Inferred`** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| State `+0x154` + flag bit2 | **Confirmed** | wrong FX re-entry |
| Event ids 9/10/11 | **Confirmed** | wrong catalog key |
| state>2 audio-only | **Confirmed** | spawn path spams FX |
| Vector_PushDword not fail | **Confirmed** | wrong mission logic |
| Product English | Tentative | cosmetic |
| Runtime multi-entry golden | Open | |

---

## 3. Surviving contract

```
void Object_SetMissionStateFx_Inferred(void *self, int newState) // thiscall, ret 4
{
  old = *(self+0x154); *(self+0x154) = newState;
  // gates: clonebase+0x88, vtbl+0x1CC linked+8, (new==old && bit2)
  TeardownSecondaryFxList(self, 1);
  *(self+0x184) |= 4;
  if (newState > 2) { complete_audio(); return; }
  // 0→event9, 1→event10(+wipe), 2→event11(+wipe); attach; push dword; audio; 004b7e50
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product C++ names / enum | No |
| R2 | Exact `FUN_004b7e50` | No for static CF |
| R3 | Runtime golden | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x00518370` — CF matches 2026-07-23 raw.  
2. `read_memory` entry + epilogue — thiscall, `+0x154`, **`ret 4`**.  
3. Caller sites: SpawnObject/`00582670` push **3**; progress wrappers compute 0..2.  
4. Cross-check W29-N teardown + bit2 clear then this unit re-arms.  
5. Reject historical FailMissionNotify mission semantics.

---

## 6. Falsifications locked in

- **Reject** treating state 3 as FX-load path.  
- **Reject** FailMissionNotify as mission-fail business logic.  
- **Reject** SpawnObject-only naming as complete role.

---

## 7. Verdict

**accept** — adversarial checks hold; residuals are product English / runtime only.
