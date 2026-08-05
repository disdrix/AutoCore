# Review B (skeptical / adversarial): `aa_004bc840` CNDHash_AllocBucketTable_009cb350

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc840` |
| **VA** | `0x004bc840` |
| **Canonical name** | `CNDHash_AllocBucketTable_009cb350` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bc840_CNDHash_AllocBucketTable_009cb350.md` |
| **System** | container / COList hashA/hashB CNDHash |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Leaves `+0x08` as power-of-two size | Terminal `ADD [ESI+8],-1` → mask | **Falsified** permanent size |
| 2 | Single `new`/`malloc` for both | Separate `new[]` table + `malloc` slab | **Falsified** single-heap |
| 3 | Sentinel = object vtbl `009cb45c` | Init writes **`009cb350`** only | **Falsified** merge stamps |
| 4 | log2 allows 0 or >16 | `CMP 1/JL; CMP 10h/JG` | **Falsified** open range |
| 5 | VOG_DEBUG_STOP is primary role | Only fail path; happy path is alloc | **Falsified** Named_VOG identity |
| 6 | Only ctor calls | Also Recreate `FUN_004bcd40` | **Falsified** sole-caller |
| 7 | Same as `004bc7a0` / mergeable | Stamp `009cb350` vs `009cb348` | **Falsified** merge twins |
| 8 | PDB AllocBucketTable proven | No product string on success path | **Agree Open**; role High OK |

---

## 2. Live ≡ raw

```
Live decompile ≡ raw 2026-07-23.
read_memory: gate 1..16; new[] N*4; malloc N*0xC; stamp 009cb350; mask N-1.
Callers: 004bcfea (ctor 004bcf90), 004bcd8c (Recreate 004bcd40).
Fail: VOG_DEBUG_STOP + throw 0x80004003.
```

Twin cross-check (same dual):

```
004bc7a0 identical CF except C7 00 48 B3 9C 00 (009cb348)
```

W28-J ctor residual closed:

```
raw ctor: *this=009cb45c; +0x08=1<<log2; FUN_004bc840(); return this
bytes:    E8 → 004bc840 unconditional before ret 4
```

⇒ Layout agreement with Alloc post-condition mask. **Agree High** with A.

---

## 3. Surviving contract

```
// void __thiscall CNDHash_AllocBucketTable_009cb350(hash*)
// require log2 in 1..16; N=count at +8;
// table=new[N]; slab=malloc(N*0xC); wire sentinels with vtbl 009cb350;
// +8 = N-1 (mask). Throw E_POINTER on bad log2.
```

---

## 4. CF challenge of Review A

- Dual alloc + mask conversion: **agree Confirmed**
- thiscall plain ret / throw fail: **agree Confirmed**
- Stamp-qualified name: **agree** — disambiguates from twin / medal family
- Callers ctor + Recreate: **agree Confirmed**
- Do not treat VOG string as identity: **agree**
- Do not substitute twin `004bc7a0` / stamp `009cb348`: **agree**

---

## 5. Residual risks

1. Product English AllocBuckets vs CreateTable.
2. Null-check absence on `new[]`/`malloc` failure (CRT throw / OOM policy).
3. Full sentinel vtbl method set at `009cb350`.
4. FreeBuckets twin body not OWN this pass (pattern known from medal FreeBuckets).
5. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, callers, mask post-condition, and AllocBucketTable role.
