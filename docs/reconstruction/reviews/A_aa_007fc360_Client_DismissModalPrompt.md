# Review A (reconstruction fidelity): `aa_007fc360` Client_DismissModalPrompt

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fc360` |
| **VA** | `0x007fc360`–`0x007fc487` |
| **Canonical name** | `Client_DismissModalPrompt` (INFERRED; Ghidra `FUN_007fc360`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual A / W17-M) |
| **Counterpart** | `reviews/B_aa_007fc360_Client_DismissModalPrompt.md` |
| **System** | client UI modal / message panel |
| **Verdict** | **accept** — body + role sealed |

---

## 1. Purpose

Shared **client modal dismiss** helper. When the message panel (`client+0x1118`, `CDlgPopup` family) and modal host holder (`client+0xf40`) exist:

- If panel reports active (`vtbl+0x3d8`): notify host (`vtbl+0xb0` with panel), hide panel (`vtbl+0x440`), optionally send pending **C2S `0x8006`** (size `0x18`) when `client+0x30f4`, restore dual-id **`+0x498/+0x49c` ← `+0x514/+0x518`**, and maybe restore secondary UI at `+0xf38` unless a blocking slot is found in `+0x1030[0..0x39]` (skip index `0x16`).
- **Always** (outer gate held): clear **`panel+0x4fd`**.

First call inside `Client_ShowModalPrompt`; also ESC-while-visible, abandon close-only, packet handlers, login UI cleanup. **Not** the show path.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007fc360_FUN_007fc360.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_007fc360_FUN_007fc360.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007fc360.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Client_DismissModalPrompt.cpp` |
| Function record | `docs/reconstruction/functions/aa_007fc360_FUN_007fc360.md` |
| Live Ghidra | `decompile_function` ≡ `force_decompile` |
| | `read_memory` 295 B body |
| | callers/callees/xrefs; related decompile of `Client_ShowModalPrompt` / `FUN_008073b0` |
| Prior residual | `reviews/a_007fdfb0.md` ESC + dual-id notes |
| Tools avoided | `disassemble_bytes` |

**Dual decompile:** identical bodies → no third-rep.

---

## 3. Signature

```c
void Client_DismissModalPrompt(void); // EAX = ClientGame*
// plain RET; frame SUB/ADD ESP,0x18
```

---

## 4. Control flow (sealed)

```
ESI = EAX (client)
if (!*(client+0x1118) || !*(client+0xf40)) return;
if (panel->vtbl+0x3d8()) {
  if (**hostHolder) host->vtbl+0xb0(panel);
  panel->vtbl+0x440();
  if (client+0x30f4) {
    clear flag;
    buf[0x18]: opcode=0x8006, [+0x11]=0, [+0x14]=9;
    FUN_008073b0(0x18, buf);  // ESI=client
  }
  if (**hostHolder) {
    host+0x498 = host+0x514;
    host+0x49c = host+0x518;
  }
  if (*(client+0xf38)) {
    for i in 0..0x39 except 0x16:
      if slot && slot->vtbl+0x3d8() && slot[0x140]==1: goto clear;
    (*(client+0xf38))->vtbl+0x3c4(client+0x31d8);
  }
}
clear: *(panel+0x4fd) = 0;
```

---

## 5. Dual-id relationship to ShowModalPrompt

| Show (`0x007fdfb0`) | Dismiss (this) |
|---|---|
| `+0x514 ← +0x498` (backup) | `+0x498 ← +0x514` (restore) |
| `+0x518 ← +0x49c` | `+0x49c ← +0x518` |
| program OK/Cancel codes into live dual-id | restore previous live dual-id |

Seals this unit as the **inverse cleanup** of modal show, not a second show implementation.

---

## 6. Gaps (non-blocking)

1. Product name / server handler for opcode **`0x8006`**.
2. Meaning of slot index **0x16** exclusion and `+0x500 == 1`.
3. Exact English for virtuals `+0x3d8` / `+0x440` / `+0xb0` / `+0x3c4`.
4. Runtime capture of dismiss with `+0x30f4` set.

---

## 7. Verdict

Body control flow, ABI, dual-id restore, packet constants, and caller role as dismiss sink are **High**. Name `Client_DismissModalPrompt` is **INFERRED** but well-supported; keep Ghidra `FUN_007fc360` for continuity. **accept**.
