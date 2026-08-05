# Review B (skeptical / adversarial): `aa_00720670` CSoundManager_RequestPlay

| Field | Value |
|---|---|
| **Stable ID** | `aa_00720670` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00720670_CSoundManager_RequestPlay.md` |
| **Verdict** | **accept-with-gaps** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | No stack args / void fastcall only | Epilogue `ret 0xC8`; 200-byte POD | **Falsified** |
| 2 | Immediately plays wave / opens device | Only sets flags + enqueues vector | **Overstated** as sync play |
| 3 | Is stop/deactivate | Stop family is `FUN_007203b0`; this is activate enqueue | **Falsified** |
| 4 | `in_stack_000000bc` is first formal | It is **tail** of 0xC8 blob (entry +0xBC) | **Clarified** — not arg0 |
| 5 | CS is at +0x158 | Body uses **+0x170** (ctor has both; stop uses +0x158) | **Falsified** if claimed 0x158 |
| 6 | Compact always runs | Only when compactFlag≠0 and mode 1 or 2 | **Falsified** |
| 7 | Mode 5 also compacts | Flag branch only handles 1 and 2 | **Falsified** |
| 8 | Product name certain without plate | Family High; method Probable | **Overstated** if claimed Confirmed name |
| 9 | Named_VOGMapText callee is product identity | Xref-weak scaffold | **Overstated** |
| 10 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 0xC8 / thiscall | **High** | Stack smash on ported callers |
| Enqueue always @ +0x70 | **High** | Lost plays |
| CS +0x170 | **High** | Race / wrong lock vs stop path |
| Mode/flag offsets | **High** | Wrong sticky / skip compact |
| Full request English | **Low** | Incomplete audio port |
| Method spelling | **Med** | Naming only |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Epilogue `c2 c8 00` | **Yes** (`read_memory`) |
| Ctor zeros +0x13..+0x15; ICS +0x170 | **Yes** (dual `aa_00720a40`) |
| `FUN_004804d0` stride 200 | **Yes** (decompile `/ 200`) |
| NDSpecialFX copies 0x32 dwords = 0xC8 | **Yes** (caller dual) |
| GetInstance before play | **Yes** (`FUN_00720d40` then this) |

**Attack on “vector is at +0x44”:** **Survives as different structure** — compact `FUN_00720090` walks `+0x44/+0x48` and `+0x54/+0x58` queues; **this** function enqueues via **`+0x70`** helper. Do not conflate.

**Attack on “mode at +0xBC is first field”:** **Falsified** — first request byte is entry `ESP+4`; mode is near end.

---

## 4. Surviving contract for AutoCore

```
// ECX = CSoundManager* (DAT_00d20070)
// push 0xC8-byte request; call; ret 0xC8
// lock +0x170
// optional compact (flag@+0xBC, mode 1|2)
// sticky +0x13/+0x14/+0x15 for modes 1/2/5
// always vector_push_200(+0x70, &req)
```

**Falsified port mistakes:**

- Calling with only mode/flag instead of full 0xC8.
- Using stop CS `+0x158` for this path.
- Skipping enqueue when sticky already set.
- Treating as synchronous PlaySound.

---

## 5. Open questions

1. Product method name.
2. Mode 1/2/5 English (music / SFX / ambient?).
3. Rest of request POD.
4. Who drains `+0x70` vector on the audio tick.

**Verdict:** **accept-with-gaps** — no residual blocking the enqueue/ABI seal; POD English remains.
