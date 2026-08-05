# Review B residual refresh (skeptical): `Client_RecvCompleteDynamicObjective` @ `0x0080ff00` (2026-07-29)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080ff00` |
| **Review type** | Skeptical residual — **not** full re-dual |
| **Counterpart** | `A_aa_0080ff00_Client_RecvCompleteDynamicObjective_residual.md` |
| **Prior dual** | `B_aa_0080ff00_Client_RecvCompleteDynamicObjective.md` (2026-07-23) |
| **Evidence** | Same Ghidra decompile/read_memory set as A residual; PacketDispatch sole-caller seal |
| **Verdict** | **accept-with-gaps** |

---

## 1. Attacks on residual claims

| # | Challenge | Outcome |
|---:|---|---|
| 1 | Opcode 0x2070 is plate-only folklore | **Falsified as open gap.** Sole caller is PacketDispatch; raw case `0x2070` invokes this VA with `param_2`. Body has no opcode immediate (normal for registered handlers). |
| 2 | CompleteObjective might run on a different this (global / vehicle) | **Falsified.** Call site `0x0080ff87`: `mov ecx, [edi+0xe98]` immediately before pushes + `call 0x00533f90`. Matches character layout used for `+0x548` hash. |
| 3 | Missing active-hash entry skips complete | **Still falsified** (prior B). Scan only mutates `worldTarget`; CompleteObjective sits after `LAB_0080ff80` with no miss-gate. |
| 4 | Force flag optional / soft-complete | **Still falsified.** Immediate `push 1` as last stack arg; callee treats non-zero force as skip failed req evals. |
| 5 | `0x41700000` is a mode/enum key not float | **Falsified.** Callee signature is `float param_1`; body uses `param_1 * param_1` as squared radius vs Δxyz. Bits `0x41700000` = IEEE `15.0f`. |
| 6 | Always SendUseObject on every 0x2070 | **Still falsified.** Gate is `worldTarget != -1` after type-3 capture; then near/list match required. |
| 7 | Portable C signature `(client, packet)` proven | **Partially weakened claim.** Packet is formal stack arg from dispatch; client is **EDI residual** (handler convention), not a second formal in decompile. Residual seals **usage**, not a rewritten MSVC prototype. |
| 8 | Type `3` is definitively "UseObject requirement" | **Not sealed.** Only sealed: first req with `vtbl+0x50()==3` contributes `req[6]` as world-id key. Collect ctor writes type **2**; full enum still open — do not invent "UseObject=3". |
| 9 | `FUN_0052d8b0` is generic "UI clear" | **Overstated name only.** Body clears `char+0x50c` mission tree with `missionId=-1`; with flag `0` it does **not** run ResolveObjectTarget cleanup. Functional wipe still holds; marketing name open. |

---

## 2. Surviving contract (AutoCore)

```
// S2C CompleteDynamicObjective (dispatch 0x2070 → 0x0080ff00)
// packet+0x10 = objectiveId (u32)
//
// Client (always):
//   clear char mission-tree at +0x50c (missionId=-1, no resolve-target side path)
//   lookup active obj by id (optional; miss does NOT skip complete)
//   optional: capture first type-3 requirement field [6] as worldTarget
//   CVOGReaction_CompleteObjective(localChar, objectiveId, -1, -1, force=1)
//   refresh mission UI / dialog chrome
//   if worldTarget != -1 and world object def id matches:
//       Client_SendUseObject (C2S 0x2072) on matched object
//   Client_RefreshOpenMissionUiWindows
//
// Server policy (external architecture, not body):
//   Do NOT emit 0x2070 on dialog deliver turn-in (client already completed locally).
//   Do NOT skip emit when client active-hash might miss — client still force-completes.
```

Risk if wrong: double-complete on dialog turn-in; silent no-op if server withholds 0x2070 when client hash empty; wrong interact spam if UseObject polarity inverted.

---

## 3. Confidence (adversarial residual)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Opcode 0x2070 ↔ this VA | **High** | Dead / wrong handler |
| Force CompleteObjective(id,-1,-1,1) on local char | **High** | Partial progress or wrong entity |
| Objective id @ packet+0x10 | **High** | Wrong mission slot |
| Hash miss still completes | **High** | Missed server force-complete |
| UseObject only if type-3 target matched | **High** | Spurious 0x2072 |
| `FUN_009197a0` = 15.0f nearest-object pick | **High** | Wrong interact target selection |
| `req` type-3 enum identity | **Tentative** | Mis-tag requirement class |
| UI object formal names | **Tentative** | Doc-only |
| Runtime / differential | **Open** | Content edge cases |

---

## 4. Open (do not invent)

1. Full `vtbl+0x50` requirement-type enum (what is type 3 vs Deliver/UseItem/Patrol/…).
2. Semantic name of `req[6]` beyond equality with `*(obj+0xa8)+0x34`.
3. Names of dialog hide helpers and `FUN_0090cbc0`.
4. Live capture of 0x2070 → force complete → optional 0x2072 ordering.
5. Bit-exact / differential vs retail EXE.

**Verdict:** residual challenges on opcode, character thiscall, force polarity, and 15.0f picker **defeated**. **accept-with-gaps.**
