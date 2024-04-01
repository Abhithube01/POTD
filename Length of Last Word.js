/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) 
{
    const words = s.trim();
    const words_ = words.split(' ');

    const lastWord = words_[words_.length - 1];

    return lastWord.length;
    
};