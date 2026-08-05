# Review B (skeptical / adversarial): `aa_0096de80` phyBone_CopySharedQsTransformToLocal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096de80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-E) |
| **Counterpart** | `reviews/A_aa_0096de80_phyBone_CopySharedQsTransformToLocal.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | ECX-thiscall | Body uses **EAX** as base; call sites `MOV EAX, bone` then CALL; ECX is temporary for shared | **Falsified** |
| 2 | Copies full shared object / bind 4x4 / shape | Only 10 dwords from +0xc..+0x30; no +0x40/+0x80 | **Falsified** |
| 3 | Writes to bone+0xf4 | Reads +0xf4; writes locals +4..+28 and +0x140 | **Falsified** |
| 4 | Sets +0x140 to 0 (clear) | Imm is `0xffffffff` | **Falsified** |
| 5 | Has callees / does I/O | Leaf; no CALL in body hex | **Falsified** |
| 6 | Stack args / ret n | Bare `c3` | **Falsified** |
| 7 | gfxBodyMassageMachine product body | Auto-seed residual; callers are phyBone paths | **Falsified** as product name |
| 8 | Safe if shared null | No null check — assumes +0xf4 installed | **True residual** (caller contract) |
| 9 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX bone ABI | **High** | Wrong register in wrappers |
| 10-float copy map | **High** | Broken skinning / root TF |
| +0x140 = -1 only | **High** | Cache not invalidated |
| No bind/shape copy | **High** | Over-port |
| Null-shared precondition | **Med** (caller must ensure) | Crash if violated |
| Product identifier spelling | **Low–Med** | Naming only |
| +0x140 English | **Med** | Doc only |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body hex via `read_memory` | **Yes** — starts `8b 88 f4…`, ends `…ffffffff 5e c3` |
| Call sites set EAX=bone | **Yes** (`MOV EAX,ESI` / `MOV EAX,EBP`) |
| Parent order: install → BDAT → this | **Yes** phyBone_unserialize |
| Shared layout matches CreateDefault | **Yes** (+0xc..+0x30 qs block) |

**Attack on “this is a full deep-copy of shared data”:** **Fails** — qs block only + sentinel.

**Attack on “ECX thiscall copy into shared”:** **Fails** — EAX bone; direction shared→bone.

---

## 4. Surviving contract for AutoCore

```
// EAX = phyBone*
// shared = *(bone+0xf4)   // must be non-null (installed + unserialized)
// bone[+4..+28] = shared[+0xc..+0x30]   // 10×f32 qs
// bone[+0x140] = 0xffffffff
// bare ret; leaf
```

**Falsified port mistakes:**

- Using ECX as this.
- Copying bind 4x4 or collision slot here.
- Writing 0 into +0x140 instead of -1.
- Calling before shared install/unserialize without null guard (retail assumes set).

---

## 5. Open questions

1. Product/PDB method name.
2. English of +0x140 sentinel consumers.
3. Runtime / bit-exact.

**Verdict:** **accept** — sealed CF/ABI/copy map; reject full-copy and ECX myths.
