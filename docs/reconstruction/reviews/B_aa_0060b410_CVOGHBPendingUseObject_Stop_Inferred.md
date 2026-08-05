# Review B (skeptical / adversarial): `aa_0060b410` CVOGHBPendingUseObject_Stop_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060b410` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-T) |
| **Counterpart** | `reviews/A_aa_0060b410_CVOGHBPendingUseObject_Stop_Inferred.md` |
| **Verdict** | **accept** on CF/ABI; **needs-more-evidence** only on product English |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `FUN_00535ed0` uses ECX=this HB | **Falsified** — bytes `mov ecx,[esi+0x28]` before call |
| 2 | Single-arg EndOrDestroy | **Falsified** — two `push 1`; EndOrDestroy dual sealed arity 2 |
| 3 | Always cancels pending | **Falsified** — flag==0 skips cancel (resolve clear path) |
| 4 | Cancels without owner check | **Falsified** — requires `+0x18 != 0` |
| 5 | cdecl / no stack cleanup | **Falsified** — `ret 4` |
| 6 | Scaffold name is product | **Falsified** — callee-chain label only |
| 7 | Leaf / no callees | **Falsified** — Resolve + virtual EndOrDestroy |
| 8 | Same as generic `CVOGHBBase_Stop` | **Falsified** — Stop is `0x005081d0` dormant+OnEnd; this is cancel+EndOrDestroy hard |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Flag/owner/character CF | **High** | Wrong pending cancel |
| EndOrDestroy `(1,1)` | **High** | Soft vs hard teardown |
| thiscall ret 4 | **High** | ABI break |
| Identity as `+0xca0` aux | **High** | callers only pass that object |
| Product English | **Tentative** | Docs only |

---

## 3. Cross-check against raw + bytes

```
cmp [esp+4],0 / jz skip
cmp [esi+0x18],0 / jz skip
mov ecx,[esi+0x28]; push 0; call Resolve
push 1; push 1; call [vtbl+0x18]
pop esi; ret 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Body end `0x0060b438` via `get_function_by_address`.

Clean preserves spine. **No invented callers.** Flag polarity preserved (1=cancel, 0=skip).

---

## 4. Surviving contract for AutoCore

```
// When tearing down char+0xca0 pending-use HB:
//   flag=1 → cancel pending (commit 0) if owned, then hard EndOrDestroy
//   flag=0 → EndOrDestroy only (caller already resolving)
StopPendingUseObjectHb(hb, flag_cancel_pending);
```

Port must **not** call Resolve with ECX=HB; must this-adjust to `HB+0x28` character.

---

## 5. Residual

- Product class name / PDB.
- Runtime sequence when RecordFirstTimeEvent replaces aux mid-pending.

**Verdict:** **accept** (CF/ABI sealed). English residual only.
