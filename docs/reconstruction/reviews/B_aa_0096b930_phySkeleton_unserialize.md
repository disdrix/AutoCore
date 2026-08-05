# Review B (skeptical / adversarial): `aa_0096b930` phySkeleton_unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096b930` |
| **VA** | `0x0096b930` |
| **Canonical name** | `phySkeleton_unserialize` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0096b930_phySkeleton_unserialize.md` |
| **System** | physics / phySkeleton asset I/O |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is phyBone unserialize | Tag is PSKE not PBON; loops bones | **Falsified** |
| 2 | This is phySkeletonMaster | Distinct log strings for Master | **Falsified** |
| 3 | Tag is little-endian file order as API constant | Imm is `0x50534b45` (`PSKE`); file bytes `EKSP` | **Agree** both descriptions |
| 4 | Accepts any version | Hard gate `version == 1` only | **Falsified** multi-version claim |
| 5 | Always binary path | Branch on `reader+0x4044` | **Falsified** |
| 6 | thiscall / ECX = self | Stack formals; parent pushes two; **RET 8** | **Falsified** thiscall model |
| 7 | Success returns void / always 0 | Returns int-read status `uVar2` | **Falsified** |
| 8 | Fail returns 0 | Both fail tails `0xffffffff` / `OR EAX,-1` | **Falsified** |
| 9 | Bone index written inside phyBone_unserialize | phyBone dual + this loop store `+0x144` after call | **Falsified** nested claim |
| 10 | Sole parent is unknown | Two xrefs both `FUN_00765740` (gfxBody) | **Falsified** |
| 11 | Leave scope always | Conditional on scope flag `local_18` | **Agree** conditional |
| 12 | Product path inventable | String at `0x00aa1254` | **Falsified** invention |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 8 / two stack formals | **Confirmed** | Stack imbalance in ports |
| PSKE + version 1 gate | **Confirmed** | Accept corrupt assets |
| Bone loop + index stamp | **Confirmed** | Broken skinning / hierarchy |
| Binary/text dual read | **Confirmed** | Text asset path dead |
| Nested `FUN_0096b150` role | **High** CF / **Open** English | Wrong resize semantics |
| Flag `\|3` / gen `+1` meaning | **Open** | Miss dirty/rebuild triggers |
| Runtime | **Open** | No live PSKE capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live batch_decompile (2026-08-04);
bytes @ 0x0096b930 (329 B):
  SEH push -1 / LAB_009b3077 / fs:0
  call stoChunkReader_EnterChunkScope
  cmp [tag], 0x50534b45 ('PSKE')
  jne log_invalid_tag (line 0x3a)
  version-1 check → else format+log (line 0x53)
  test [reader+0x4044]; binary FUN_00437050 / text FUN_007689e0
  call FUN_0096b150(self, count)
  loop [self+0x0C .. self+0x10): phyBone_unserialize; [bone+0x144]=index
  add [self+0x1C],1; or [self+4],3
  leave scope if flag; ret 8
  fail: or eax,-1; leave; ret 8
```

### ABI trap

Do **not** model as thiscall. Parent gfxBody path pushes **reader + skeleton@body+0x98** and expects **RET 8**.

### Index trap

`phyBone_unserialize` does **not** set `+0x144`; this VA does **after** the call. Ports that drop the stamp break bone index tables.

### Version trap

There is **no** v2/v3 arm in this function — unlike gfxBody parent which has multi-version outer logic. Feeding PSKE v2 here hard-fails.

### Master trap

Do **not** confuse with phySkeletonMaster plates (`0x00aa6ad0` / `0x00aa6b20`) — different VA family.

---

## 4. Surviving contract for AutoCore

```
phySkeleton_unserialize(self, reader):
  EnterChunkScope(reader)
  if tag != PSKE (0x50534b45): log line 0x3a; return -1
  if ver != 1: log line 0x53; return -1
  count_status = ReadI32(reader, &count)  // binary/text via reader+0x4044
  FUN_0096b150(self, count)
  for i, bone in enumerate(self.bones):
    phyBone_unserialize(reader, bone)
    bone.index_0x144 = i
  self.gen_0x1C += 1
  self.flags_0x04 |= 3
  LeaveScope_if(flag)
  return count_status

Consumers:
  gfxBody unserialize (FUN_00765740) → skeleton at body+0x98

AutoCore must NOT:
  - accept non-v1 PSKE here
  - skip bone index stamp
  - model as thiscall / RET 0
  - fold phyBone or FUN_0096b150 into this VA without separate duals
  - invent Master semantics
```

---

## 5. Verdict

**accept-with-gaps** — adversarial checks fail to break tag/version/ABI/bone-loop contract; residual is nested helper English, flag semantics, and runtime.
