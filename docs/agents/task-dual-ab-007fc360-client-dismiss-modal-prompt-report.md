# Dual A/B report — `aa_007fc360` Client_DismissModalPrompt

**Date:** 2026-07-29  
**Agent:** W17-M OWN-ONLY  
**Scope:** OWN ONLY VA `0x007fc360`. Dual A/B + artifacts.  
**Excluded:** Ledgers; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG; parent ownership of ShowModalPrompt residual.  
**Ghidra:** `decompile_function` + `force_decompile` + `read_memory` + callees/callers/xrefs. No `disassemble_bytes`. No Launcher.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007fc360` Client_DismissModalPrompt (`FUN_007fc360`) | **accept** — modal dismiss sink sealed |

---

## Sealed facts

1. **ABI:** client/game in **EAX** (`MOV ESI,EAX`); **void**; frame `SUB/ADD ESP,0x18`; plain **`RET`**.

2. **Body range:** `0x007fc360`–`0x007fc487` (**295 B**). Dual decompile reps **identical** → no third-rep.

3. **Algorithm (exact):**
   - Outer gate: `client+0x1118` (panel) and `client+0xf40` (host holder) non-null.
   - If panel `vtbl+0x3d8` active:
     - host `vtbl+0xb0(panel)` when host object present;
     - panel `vtbl+0x440` dismiss;
     - if `client+0x30f4`: clear; send **size 0x18** packet opcode **`0x8006`**, byte0 @+0x11, dword **9** @+0x14 via `FUN_008073b0`;
     - restore dual-id **`host+0x498←+0x514`**, **`+0x49c←+0x518`**;
     - if `client+0xf38`: scan slots `+0x1030` indices `0..0x39` skip **`0x16`**; if any slot active (`+0x3d8`) and dword `+0x500==1`, skip restore; else `*(+0xf38)->vtbl+0x3c4(byte at +0x31d8)`.
   - Always under outer gate: **`*(panel+0x4fd)=0`**.

4. **Role:** shared **dismiss** inverse of `Client_ShowModalPrompt` dual-id backup; first call of show; ESC path; abandon close-only; packet/login UI cleanup.

5. **Callees:** panel/host virtuals; `FUN_008073b0` @ `0x008073b0`.

6. **Call surface:** inventory **64** xrefs.

7. **Name:** **INFERRED** `Client_DismissModalPrompt`; keep Ghidra `FUN_007fc360` / `aa_007fc360`. Legacy PacketDispatch-only alias underspecific.

8. **Bytes ≡ decompile** (body hex in raw append / Review A).

---

## Gaps

1. Product English for opcode **`0x8006`** / field **9**.  
2. Slot index `0x16` exclusion and `+0x500==1` product meaning.  
3. Virtual method product names (`+0x3d8`/`+0x440`/`+0xb0`/`+0x3c4`).  
4. Runtime dismiss with pending `+0x30f4`.  
5. Bit-exact image diff.

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_007fc360_Client_DismissModalPrompt.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_007fc360_Client_DismissModalPrompt.md` | **accept** |

Three-rep: **not required**.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_007fc360_Client_DismissModalPrompt.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007fc360_Client_DismissModalPrompt.md` |
| Function record | `docs/reconstruction/functions/aa_007fc360_FUN_007fc360.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007fc360.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/Client_DismissModalPrompt.cpp` |
| Raw (+ v2026-07-29 append) | `docs/reconstruction/raw/aa_007fc360_FUN_007fc360.md` |
| Annotated | `docs/reconstruction/raw/aa_007fc360_FUN_007fc360.annotated.md` |
| This report | `docs/agents/task-dual-ab-007fc360-client-dismiss-modal-prompt-report.md` |

---

## AutoCore impact

- Wire modal lifecycle: **Dismiss** before/without Show; restore dual-id backups — do not zero them.
- Optional **`0x8006`** only when pending flag set; size **0x18**.
- ESC / abandon close-only paths should call this sink, not re-implement hide logic.
- Prefer stable id `aa_007fc360` / `FUN_007fc360` in code until name is registry-promoted.
