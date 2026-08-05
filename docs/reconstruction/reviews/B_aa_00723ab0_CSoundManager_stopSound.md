# Review B (skeptical / adversarial): `CSoundManager::_stopSound` @ `0x00723ab0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00723ab0` |
| **VA** | `0x00723ab0` |
| **Body span** | `00723ab0` – `00723b14` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra; independent of Review A wording) |
| **Counterpart** | `reviews/A_aa_00723ab0_CSoundManager_stopSound.md` |
| **System** | client audio / `CSoundManager` |
| **Verdict** | **accept-with-gaps** on OWN CF/ABI; **needs-more-evidence** on `+0x1b0` product field and fade helper |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This frees / destroys the sound instance | **Falsified** — only flag + float writes; pointer stays in table |
| 2 | Index is a normal stack/`this` parameter | **Falsified** — index is **EAX-only** (`cmp eax,30h`) |
| 3 | Ghidra success path `uVar2` / `extraout_ECX` is real dataflow | **Falsified** — body reuses **ECX=this**, **EAX=index** after call; float result is **ST0** only (`fstp [edx+0x1b0]`) |
| 4 | `return in_EAX & 0xffffff00` is the fail status | **Overstated decomp** — fail is **`xor al,al; ret`** (AL=0). High bytes of EAX may be stale; treat as **bool in AL** |
| 5 | Always logs on failure | **Falsified** — range/null fail is silent; only bad flags log |
| 6 | `+0x38=1` means “playing” | **Falsified by log** — “already stopped(%d)” binds first `%d` to `+0x38` |
| 7 | Stop uses a caller-supplied fade argument | **Falsified** — always `push 0` into `FUN_007227e0` → fixed **−10000.0f** |
| 8 | Runtime verified | **Falsified** — open / deferred |
| 9 | Scaffold clean (2026-07-23) was production-ready | **Overstated** — carried decompiler extras; 2026-07-29 clean rewrites CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX index / ECX this / AL return | **High** | Wrong ABI → stops wrong slot or no-op |
| Cap **48** slots (`0x30`) | **High** | OOB table walk |
| Table `this+0x31c` | **High** | Wrong manager layout |
| Flag gate both-zero | **High** | Double-stop spam / refuse valid stops |
| Mark `+0x38=1`, clear `+0x3a` | **High** | Sticky start-playing / never-stopped |
| Write `+0x1b0 = -10000.0f` | **High (value)**; field role **Tentative** | Port that skips write may leave audio engine running |
| Product name `_stopSound` | **High** | Naming only |
| `FUN_007227e0` general math | **Out of scope** | Dual OWN-only |
| Clean ≡ asm CF (after rewrite) | **High** | Safe stop map |

---

## 3. Surviving contract for AutoCore

```
// this: ECX; index: EAX; return: AL
ok = CSoundManager__stopSound(this, index_in_EAX):
  if index >= 48: return 0
  inst = this.slots_0x31c[index]
  if inst == null: return 0
  if inst.byte_0x38 != 0 OR inst.byte_0x3a != 0:
    log("_stopSound ... stopped(%d)=byte_0x38, start(%d)=byte_0x3a")
    return 0
  inst.f32_0x1b0 = fadeCurve(0.0f)   // retail: -10000.0f
  inst.byte_0x38 = 1
  inst.byte_0x3a = 0
  return 1
```

**Port rules that survive adversarial review:**

1. Never invent a stack index arg — keep EAX (or wrapper that loads EAX).
2. Do **not** free the slot pointer; only mark flags + write envelope float.
3. Preserve silent fail on OOB/null vs logged fail on bad flags.
4. Write **−10000.0f** (or call the same helper) at `+0x1b0` before marking stopped if matching retail audio behavior.

---

## 4. CF cross-check vs three-rep

| Check | Result |
|---|---|
| Live decompile vs scaffold raw plate | **Match** plate; **mismatch** decompiler extras |
| Annotated asm vs `read_memory` | **Match** |
| Clean (2026-07-29) vs asm stages | **Match** (extras removed) |
| Sibling `00723b20` claim that this is `_stopSound` | **Sealed** by own string |

---

## 5. Open questions (OWN residual only)

1. Exact audio-engine meaning of `−10000.0f` at `+0x1b0` (instant mute? invalid? dB floor?).
2. Whether any caller depends on EAX high bytes after success (loads instance then `mov al,1`).
3. Interaction with `slot+0x1c5` “active” used by StopMatching — not read here.
4. Runtime not run.

**Verdict:** **accept-with-gaps** on OWN control flow, ABI, flags, and product name; **needs-more-evidence** before naming `+0x1b0` or treating `FUN_007227e0` as a general public API. Safe behavioral map for AutoCore single-slot stop.
