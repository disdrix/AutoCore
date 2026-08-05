# Review B (skeptical / adversarial): `aa_0051ba40` CNDHash_AllocBucketTable_009ce090

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051ba40` |
| **VA** | `0x0051ba40` |
| **Canonical name** | `CNDHash_AllocBucketTable_009ce090` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0051ba40_CNDHash_AllocBucketTable_009ce090.md` |
| **System** | container / medal CNDHash |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Leaves `+0x08` as power-of-two size | Terminal `ADD [ESI+8],-1` → mask | **Falsified** permanent size |
| 2 | Single `new`/`malloc` for both | Separate `new[]` table + `malloc` slab | **Falsified** single-heap |
| 3 | Sentinel = node stamp `009ce0a8` | Init writes **`009ce090`** only | **Falsified** merge stamps |
| 4 | log2 allows 0 or >16 | `CMP 1/JL; CMP 10h/JG` | **Falsified** open range |
| 5 | VOG_DEBUG_STOP is primary role | Only fail path; happy path is alloc | **Falsified** Named_VOG identity |
| 6 | Only Recreate calls | Also ctor `FUN_0051db60` | **Falsified** sole-caller |
| 7 | PDB AllocBucketTable proven | No product string on success path | **Agree Open**; role High OK |
| 8 | Same function as `00413d80` | Different stamp + address family | **Falsified** merge |

---

## 2. Live ≡ raw

```
Live decompile ≡ raw 2026-07-23.
read_memory: gate 1..16; new[] N*4; malloc N*0xC; stamp 009ce090; mask N-1.
Callers: 0051d27c (Recreate), 0051dbba (ctor).
Fail: VOG_DEBUG_STOP + throw 0x80004003.
```

FreeBuckets cross-check (sealed W24-H):

```
free(*buckets)  → slab base (= table[0])
delete[] buckets → pointer table
```

⇒ Layout agreement with Alloc. **Agree High** with A.

---

## 3. Surviving contract

```
// void __thiscall CNDHash_AllocBucketTable_009ce090(hash*)
// require log2 in 1..16; N=count at +8;
// table=new[N]; slab=malloc(N*0xC); wire sentinels with vtbl 009ce090;
// +8 = N-1 (mask). Throw E_POINTER on bad log2.
```

---

## 4. CF challenge of Review A

- Dual alloc + mask conversion: **agree Confirmed**
- thiscall plain ret / throw fail: **agree Confirmed**
- Stamp-qualified name: **agree** — disambiguates from `00413d80`
- Callers Recreate + ctor: **agree Confirmed**
- Do not treat VOG string as identity: **agree**

---

## 5. Residual risks

1. Product English AllocBuckets vs CreateTable.
2. Null-check absence on `new[]`/`malloc` failure (CRT throw / OOM policy).
3. Full sentinel vtbl method set at `009ce090`.
4. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, callers, mask post-condition, and AllocBucketTable role.
