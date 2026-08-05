# Review A (reconstruction fidelity): `aa_00720670` CSoundManager_RequestPlay

| Field | Value |
|---|---|
| **Stable ID** | `aa_00720670` |
| **VA** | `0x00720670` |
| **Body** | `0x00720670` – `0x0072071a` |
| **Canonical name** | `FUN_00720670` (Probable: `CSoundManager_RequestPlay`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (sound play enqueue) |
| **Counterpart** | `reviews/B_aa_00720670_CSoundManager_RequestPlay.md` |
| **System** | client audio / `CSoundManager` |
| **Path context** | Singleton `DAT_00d20070`; GetInstance `0x00720d40`; ctor CS/flags dual `aa_00720a40` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Enqueue a by-value 0xC8-byte play request** onto the sound manager under `CRITICAL_SECTION` at `this+0x170`:

1. Optionally **compact** pending queues via `FUN_00720090` when request **compactFlag** set and mode ∈ {1,2}.
2. Raise sticky bytes **`this+0x13` / `+0x14` / `+0x15`** for modes **1 / 2 / 5**.
3. **Always** `FUN_004804d0(this+0x70, &req)` — append 200-byte element to manager vector.
4. Unlock; **`ret 0xC8`**.

Activate-side companion to stop/mark helpers (`FUN_007203b0`). Used by NDSpecialFX audio list walk (`FUN_004b6fc0`) after GetInstance.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00720670_FUN_00720670.md` (+ live refresh) |
| Annotated | `docs/reconstruction/raw/aa_00720670_FUN_00720670.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00720670.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/CSoundManager_RequestPlay.cpp` |
| Function record | `docs/reconstruction/functions/aa_00720670_FUN_00720670.md` |
| Live decompile | ≡ raw |
| Body / epilogue | `read_memory` — SEH + CS + mode cmps + `c2 c8 00` |
| Ctor dual | sticky `+0x13..+0x15`, CS `+0x170` |
| Callee `FUN_004804d0` | 200-byte element stride (`/ 200` in decompile) |
| Callers | 7 xrefs via `get_xrefs_to` |

**Not performed:** `disassemble_bytes`, Launcher, live audio. **OWN VA.**

---

## 3. Signature

```c
void __thiscall CSoundManager_RequestPlay(void *self /* ECX */, SoundPlayRequest req /* 0xC8 */);
// ret 0xC8
```

| Request field | Offset in POD | Evidence |
|---|---|---|
| `mode` (int) | `+0xB8` | entry `ESP+0xBC`; cmp 1/2/5 |
| `compactFlag` (u8) | `+0xBC` | entry `ESP+0xC0`; compact gate; matches `FUN_00720090` scan @ elem+0xBC |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH + EnterCS(+0x170) | **Yes** |
| Flag gate → compact modes 1/2 | **Yes** |
| Sticky 0x13/14/15 | **Yes** |
| Enqueue +0x70 always | **Yes** |
| LeaveCS + ret 0xC8 | **Yes** |

---

## 5. Callers

| Site | Function | Notes |
|---|---|---|
| `0x004b6ffb` | `FUN_004b6fc0` | NDSpecialFX activate play list |
| `0x00720cfe`, `0x00720d1b` | `FUN_00720b50` | two hardcoded requests |
| `0x005ab73a`, `0x005ab923` | `FUN_005ab170` | |
| `0x008bbafb` | `FUN_008bb9e0` | |
| `0x0094797a` | `FUN_00946c00` | |

---

## 6. Confidence

| Claim | Level |
|---|---|
| ABI ret 0xC8 + thiscall | **Confirmed** |
| CS / vector / sticky offsets | **Confirmed** |
| Mode/flag tail fields | **Confirmed** |
| CSoundManager family | **High** |
| Method English `RequestPlay` | **Probable** |
| Full 0xC8 layout | **Open** |

---

## 7. Gaps

1. Product method name.
2. Mode enum English (1/2/5).
3. Sticky flag English (`+0x13..+0x15`).
4. Remainder of play-request POD (path, gain, 3D, …).
5. Full dual of compact `FUN_00720090` / vector `FUN_004804d0`.
6. Runtime / bit-diff.

**Verdict:** **accept-with-gaps** — enqueue contract sealed; POD/English residual.
