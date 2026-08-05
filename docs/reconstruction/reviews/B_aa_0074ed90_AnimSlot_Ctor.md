# Review B (skeptical / adversarial): `aa_0074ed90` AnimSlot_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ed90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-R) |
| **Counterpart** | `reviews/A_aa_0074ed90_AnimSlot_Ctor.md` |
| **Scratch** | `tmp/a_0074ed90.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a dtor / teardown | **Falsified** — only stores constants; callers pair with `FUN_0074ecf0` dtor separately |
| 2 | Writes a vtable at +0 | **Falsified** — no store to `[eax+0]` |
| 3 | Rate default 0 / mode clamp(0) | **Falsified** — `+0x3c=g_flOne`, `+0x4c=1` |
| 4 | Object size 0x50 / 0x5c | **Falsified** — stores through `+0x74`; callers `new(0x78)` |
| 5 | Has nested calls / heap | **Falsified** — leaf; SEH cookie only |
| 6 | Zeroes entire 0x78 with memset | **Falsified** — selective stores; gaps at +0x00/+0x14/+0x24 |
| 7 | Unrelated to SetTime fields | **Falsified** — defaults match SetTime's rate/mode/time block |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf field table | **High** | Wrong anim defaults at load |
| ABI ECX-only | **High** | Bad calling convention |
| Size 0x78 | **High** | Heap corruption |
| rate/mode defaults | **High** | Clamp vs wrap mismatch |
| Unwritten gaps | **High** | Invented zeros hide bugs |

---

## 3. Cross-check against raw + bytes

```
SEH; slot=ECX
write zeros / 0.0f across documented offsets
+0x3c = 1.0f; +0x4c = 1; +0x50/+0x60/+0x68 = -1; +0x54 = 1
teardown SEH; ret
```

Clean must **preserve** unwritten gaps and **not** invent a vtable install.

Hex seal: `6aff68c1fc9a0064a1000000005064892500000000518bc133c989480489480889480c0f57c0f30f11401089481889481c894820f30f100da0f2a00089482889482c89483083caff884855884856f30f114034f30f114038f30f11483cf30f114040f30f114044f30f114048c6404c01895050c640540189485889485c895060f30f114064895068f30f11406c8948708948748b4c240464890d0000000083c410c3`

---

## 4. Surviving contract for AutoCore

```c
// Port of AnimSlot_Ctor — after operator_new(0x78)
void AnimSlot_Ctor(AnimSlot* s) {
  // selective defaults; leave +0x00/+0x14/+0x24 untouched
  s->rate = 1.0f;   // +0x3c
  s->mode = 1;      // +0x4c wrap
  s->dw50 = s->dw60 = s->dw68 = 0xFFFFFFFFu;
  s->b54 = 1;
  // ... remaining zeros per A field table ...
}
```

---

## 5. Verdict

Adversarial pass **confirms** A: leaf ctor, 0x78 size, rate/mode defaults, unwritten gaps → **accept**.
