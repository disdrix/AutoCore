# Review B (skeptical / adversarial): `aa_0051db60` CNDHash_Ctor_009ce1a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051db60` |
| **VA** | `0x0051db60` |
| **Canonical name** | `CNDHash_Ctor_009ce1a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0051db60_CNDHash_Ctor_009ce1a0.md` |
| **System** | container / medal CNDHash |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Is Recreate not ctor | Recreate path separate (`0051d230`); this installs vtbl + zeros + Alloc | **Falsified** as Recreate |
| 2 | Is AllocBucketTable itself | Body only calls Alloc after field init | **Falsified** merge |
| 3 | log2 is full dword formal | `RET 4` + byte load `8A 4C 24 18` | **Agree** 1 stack slot, byte width |
| 4 | Writes every dword through +0x30 | +0x24 never written | **Agree** skip confirmed |
| 5 | Returns void | `MOV EAX,ESI` before epilogue | **Falsified** void |
| 6 | Many dynamic callers | Exactly 1 code xref (static init) | **Agree** |
| 7 | PDB name proven | No body string | **Agree Open** product; role High OK |
| 8 | mask already set pre-Alloc | Stores **count** N; Alloc does N−1 | **Agree** with A / Alloc dual |

---

## 2. Live ≡ raw

```
Live decompile ≡ raw 2026-07-23.
read_memory 0x73 B through C2 04 00.
Callee: FUN_0051ba40 only.
Xref: 009c0b57 (static, log2=2, this=00b042e0).
```

Alloc dual (W25-F): requires pre-set count at +0x08 and log2 at +0x1C ∈ [1,16] — **exactly** what this ctor writes before call. **Agree High** with A.

---

## 3. Surviving contract

```
// CNDHash* __thiscall CNDHash_Ctor_009ce1a0(this, log2)
// vtbl 009ce1a0; N=1<<log2 at +8; log2 at +0x1C; zero freelist/buckets;
// call AllocBucketTable; return this; ret 4
// +0x24 not written
```

---

## 4. CF challenge of Review A

- Field init order / vtbl stamp: **agree Confirmed**
- Alloc handoff thiscall: **agree Confirmed**
- Static caller log2=2: **agree Confirmed**
- Role Ctor stamp-qualified: **agree High**
- Do not merge with Recreate/Alloc/Free: **agree**
- +0x24 gap: **agree** residual, not CF blocker

---

## 5. Residual risks

1. Product class English beyond CNDHash family label.
2. Full `009ce1a0` vtbl method set.
3. Whether +0x24 is intentional padding vs latent bug (allocator zero usually).
4. Only static caller today — dynamic `new` paths may call via other thunks not yet inventoried (xref_count=1 in Ghidra).
5. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, Alloc coupling, and name.
